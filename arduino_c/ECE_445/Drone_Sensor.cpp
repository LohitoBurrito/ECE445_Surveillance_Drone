#include "Drone_Sensor.h"

Plane_Sensor::Plane_Sensor() : i2c_bus(1) { // Initialize i2c_bus with bus number
    if (!i2c_bus.begin(SDA_PIN, SCL_PIN)) { // Initialize the I2C bus (specify SDA and SCL pins)
        Serial.println("Failed to initialize I2C bus");
        while (1);
    }

    if (!bme.begin(0x76, &i2c_bus)) {  // Use custom I2C address and bus
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    if (!mpu.begin(0x68, &i2c_bus)) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) {
            delay(10);
        }
    }
    
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    for (int i = 0; i < 6; i++) {
        sensorData[i] = 0.0;
    }
}

float* Plane_Sensor::getSensorData() {
    mpu.getEvent(&a, &g, &temp);

    float roll  = atan2(a.acceleration.y, a.acceleration.z) * 180 / PI;
    float pitch = atan(-a.acceleration.x / sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180 / PI;
    float lin_accel = sqrt(pow(a.acceleration.x, 2) + pow(a.acceleration.y, 2) + pow(a.acceleration.z, 2));

    sensorData[0] = bme.readAltitude(SEALEVELPRESSURE_HPA);
    sensorData[1] = roll;
    sensorData[2] = pitch;
    sensorData[3] = lin_accel; // Corrected index from 6 to 5

    return sensorData;
}