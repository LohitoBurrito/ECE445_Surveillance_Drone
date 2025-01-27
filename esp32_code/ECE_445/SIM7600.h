#include "I2C.h"
#include "FifoCamera.h"
#include <JPEGENC.h>
#include <HardwareSerial.h>
#include <queue>
#include <mutex>
#include <Base64.h>  // Ensure you include a Base64 library
#include <sstream>
#include <string>
#include "Drone_Sensor.h"
#include "Servo_Control.h"

#define SIM7600_TX_PIN 35  // TX pin for SIM7600
#define SIM7600_RX_PIN 20  // RX pin for SIM7600

#define VSYNC 42 // vertical sync
#define SIOD 5  // SDA
#define SIOC 4  // SCL

#define RRST 14 // read reset
#define WRST 13 // write reset
#define RCK 11  // read clock
#define WR 12   // write flag

#define D0 10
#define D1 9
#define D2 8
#define D3 18
#define D4 17
#define D5 16
#define D6 15
#define D7 41

#define XRES 160
#define YRES 120
#define BYTES_PER_PIXEL 2

struct sensorPacket {
  double altitude = 0;
  double lin_accel = 0;
  double roll = 0;
  double pitch = 0;
  double yaw = 0;
  double latitude = 0;
  double longitude = 0;
};

class SIM7600 {
    public:
        /* Helper Functions */

        String sendATCommand(String command);
        int getHTTPStatusCode(String response);

        /* Sensor Data */
        void getSensorData();
        void getGPS();
        double transform(double ddmm);
        // String getImage();

        /* HTTP Requests */
        void postData();
        void commandServo();

        /* Constructor */
        SIM7600();

    private:

        /* SIM7600 Private Variables */
        HardwareSerial sim7600;

        /* Sensor Private Variables */
        struct sensorPacket pkt;
        Plane_Sensor* sensor;

        /* Servo Params */
        ServoControl* servoControl;
        int command = -1;
        int command_counter = 0;
};