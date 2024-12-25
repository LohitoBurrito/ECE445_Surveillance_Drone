#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_MPU6050.h>
#include <math.h>

#define SDA_PIN 6
#define SCL_PIN 7
#define SEALEVELPRESSURE_HPA 1010

class Plane_Sensor {
public:
    Plane_Sensor();
    float* getSensorData();

private:
    TwoWire i2c_bus;
    Adafruit_BME280 bme;
    Adafruit_MPU6050 mpu;
    sensors_event_t a, g, temp;
    float sensorData[4];
};