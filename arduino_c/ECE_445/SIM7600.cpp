#include "SIM7600.h"

/*---------------------------------------- CONSTRUCTOR --------------------------------------------------*/

SIM7600::SIM7600(): sim7600(2) {
    sim7600.begin(115200, SERIAL_8N1, SIM7600_RX_PIN, SIM7600_TX_PIN);
    delay(3000);
    sendATCommand("AT");
    sendATCommand("AT+CGPS=1");

    sendATCommand("AT+HTTPTERM");
    sendATCommand("AT+HTTPINIT");

    sensor = new Plane_Sensor();
    servoControl = new ServoControl();
}

/*---------------------------------------- HELPER FUNCTIONS --------------------------------------------------*/

String SIM7600::sendATCommand(String command) {
    while (sim7600.available()) {
        sim7600.read();
    }

    sim7600.println(command);
    Serial.println("Sending: " + command);

    delay(150);

    String response = "";
    while (sim7600.available()) {
        char c = sim7600.read();
        response += c;
    }

    if (response.length() > 0) {
        Serial.println("Response: " + response);
        return response;
    } else {
        response = "No response from SIM7600.";
        Serial.println(response);
        return "BAD OUTPUT";
    }
}

int SIM7600::getHTTPStatusCode(String response) {
    int firstCommaIndex = response.indexOf(',');
    int secondCommaIndex = response.indexOf(',', firstCommaIndex + 1);
    String statusCodeStr = response.substring(firstCommaIndex + 1, secondCommaIndex);
    int statusCode = statusCodeStr.toInt();
    Serial.println("Status Code: " + String(statusCode));
    return statusCode;
}

/*---------------------------------------- SENSOR FUNCTIONS --------------------------------------------------*/

void SIM7600::getSensorData() {
    float* sensorData = sensor->getSensorData();
    // getGPS();

    pkt.altitude = sensorData[0];
    pkt.roll = sensorData[1];
    pkt.pitch = sensorData[2];
    pkt.lin_accel = sensorData[3];
    pkt.yaw = 0;

    Serial.println("Altitude: " + String(pkt.altitude));
    Serial.println("Roll: " + String(pkt.roll));
    Serial.println("Pitch: " + String(pkt.pitch));
    Serial.println("Yaw: " + String(pkt.yaw));
    Serial.println("Longitude: " + String(pkt.longitude));
    Serial.println("Latitude: " + String(pkt.latitude));
    Serial.println("Lin Accel: " + String(pkt.lin_accel));
}

/*---------------------------------------- GPS FUNCTIONS --------------------------------------------------*/

double SIM7600::transform(double ddmm) {
    int degrees = static_cast<int>(ddmm / 100);  // Get the integer part (degrees)
    double minutes = ddmm - degrees * 100;  // Get the fractional part (minutes)
    return degrees + minutes / 60.0;  // Convert to decimal degrees
}

void SIM7600::getGPS() {
  String gpsInfo = sendATCommand("AT+CGPSINFO");
  delay(1000);

  std::string value;
  double lon, lat;
  char lon_dir, lat_dir;

  std::stringstream ss(gpsInfo.c_str());
  std::getline(ss, value, ' ');

  std::getline(ss, value, ',');
  lat = std::stod(value);
  std::getline(ss, value, ',');
  lat_dir = value[0];
  std::getline(ss, value, ',');
  lon = std::stod(value);
  std::getline(ss, value, ',');
  lon_dir = value[0];

  lat = transform(lat);
  lon = transform(lon);

  if (lat_dir == 'S') lat = -lat;
  if (lon_dir == 'W') lon = -lon;

  pkt.latitude = lat;
  pkt.longitude = lon;
}

/*---------------------------------------- POSTING FUNCTIONS --------------------------------------------------*/

void SIM7600::postData() {
    getSensorData();
    String url = "https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/SensorData?documentId=SensorData";
    String base64Image = "dapper";
    
    sendATCommand("AT+HTTPPARA=\"URL\",\"" + url + "\"");
    delay(500);

    // Set content type to JSON
    sendATCommand("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
    delay(500);

    String jsonData = "{"
                        "\"fields\": {"
                        "\"BMP280\": {"
                        "\"stringValue\": \"" + String(pkt.altitude) + "\""
                        "},"
                        "\"MPU6050\": {"
                        "\"mapValue\": {"
                        "\"fields\": {"
                        "\"linear_accel\": {\"stringValue\": \"" + String(pkt.lin_accel) + "\"},"
                        "\"Yaw\": {\"stringValue\": \"" + String(pkt.yaw) + "\"},"
                        "\"Pitch\": {\"stringValue\": \"" + String(pkt.pitch) + "\"},"
                        "\"Roll\": {\"stringValue\": \"" + String(pkt.roll) + "\"}"
                        "}"
                        "}"
                        "},"
                        "\"SIM7600\": {"
                        "\"mapValue\": {"
                        "\"fields\": {"
                        "\"Latitude\": {\"stringValue\": \"" + String(pkt.latitude) + "\"},"
                        "\"Longitude\": {\"stringValue\": \"" + String(pkt.longitude) + "\"}"
                        "}"
                        "}"
                        "},"
                        "\"Image\": {"
                        "\"stringValue\": \"" + base64Image + "\""
                        "}"
                        "}"
                        "}";

    // Specify the data length and send JSON
    String dataCommand = "AT+HTTPDATA=" + String(jsonData.length()) + ",60000";
    Serial.println(jsonData);
    sendATCommand(dataCommand);
    sim7600.print(jsonData);
    delay(500);
    String response = sendATCommand("AT+HTTPACTION=1");
    int statusCode = getHTTPStatusCode(response);

    if (statusCode != 200 && statusCode != 0 && statusCode != 204) {
        Serial.println();
        Serial.println("REBOOTING...");
        sendATCommand("AT+HTTPTERM");
        sendATCommand("AT+HTTPINIT");
        delay(5000);
        return;
    }
}

/*---------------------------------------- SERVO FUNCTIONS --------------------------------------------------*/

void SIM7600::commandServo() {
    sendATCommand("AT+HTTPPARA=\"URL\",\"https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/Commands/command" + String(command_counter) + "\"");
    delay(500);
    String response = sendATCommand("AT+HTTPACTION=0");

    int statusCode = getHTTPStatusCode(response);
    if (statusCode != 200 && statusCode != 0 && statusCode != 204) {
      Serial.println();
      Serial.println("REBOOTING...");
      sendATCommand("AT+CRESET");
      delay(5000);
      return;
    }

    delay(500);
    response = sendATCommand("AT+HTTPREAD?");

    if (response.indexOf("{") != -1 || response.indexOf("error") != -1) {
      Serial.println("ERROR or NO COMMAND");
      servoControl->updateServo(-1);

    } else if (response.indexOf("LEN,") != -1) {
        int startIndex = response.indexOf("LEN,") + 4;
        int endIndex = response.indexOf('\n', startIndex);
        String lengthString = response.substring(startIndex, endIndex);

        if (lengthString.toInt() > 200) {
          String output = sendATCommand("AT+HTTPREAD=" + lengthString);
          delay(1000);

          // for servos
          int servoStartIndex = output.indexOf("\"servo_cmd\"");
          servoStartIndex = output.indexOf("\"stringValue\": \"", servoStartIndex) + 16;
          int servoEndIndex = output.indexOf('\n', servoStartIndex);

          if (servoEndIndex > servoStartIndex) {
              String commandValue = output.substring(servoStartIndex, servoEndIndex - 1);
              Serial.println("SERVO INPUT = " + commandValue);
              servoControl->updateServo(commandValue.toInt());
              command_counter += 1;
              delay(100);
          }

          // for motor
          int motorStartIndex = output.indexOf("\"motor_speed\"");
          motorStartIndex = output.indexOf("\"stringValue\": \"", motorStartIndex) + 16;
          int motorEndIndex = output.indexOf('\n', motorStartIndex);

          if (motorEndIndex > motorStartIndex) {
              String commandValue = output.substring(motorStartIndex, motorEndIndex - 1);
              Serial.println("MOTOR INPUT = " + commandValue);
              // ESC.write(commandValue.toInt());
          }
        }
    }
    delay(1000);
}

/*---------------------------------------- IMAGE FUNCTIONS --------------------------------------------------*/

// void getImage() {
//     while (!digitalRead(VSYNC));    // Wait for frame start
//     while (digitalRead(VSYNC));     // Wait for frame end
//     camera.prepareCapture();
//     camera.startCapture();
//     while (!digitalRead(VSYNC));    // Wait for frame end
//     camera.stopCapture();

//     unsigned char* frame = (unsigned char*)ps_malloc(XRES * YRES * BYTES_PER_PIXEL);
    
//     Serial.println("Reading frame...");
//     camera.readFrame(frame, XRES, YRES, BYTES_PER_PIXEL);
//     Serial.println("Frame read complete.");

//     uint8_t* out_jpg = (uint8_t *)ps_malloc(65536);  // Use ps_malloc instead of stack allocation
//     if (out_jpg == nullptr) {
//         Serial.println("Memory allocation failed!");
//         return;
//     }

//     JPEGENCODE enc;
//     jpgenc.open(out_jpg, 65536);
//     jpgenc.encodeBegin(&enc, XRES, YRES, JPEGE_PIXEL_RGB565, JPEGE_SUBSAMPLE_420, JPEGE_Q_MED);
//     jpgenc.addFrame(&enc, frame, XRES * 2);
//     size_t out_jpg_len = jpgenc.close();

//     // getSensorData();

//     String base64Image = base64::encode(out_jpg, out_jpg_len);

//     return base64Image;
// }