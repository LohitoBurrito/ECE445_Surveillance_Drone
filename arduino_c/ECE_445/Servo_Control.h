#include <ESP32Servo.h>

#define SERVO_LEFT_WING_PIN 21
#define SERVO_RIGHT_WING_PIN 47
#define SERVO_LEFT_TAIL_PIN 48
#define SERVO_RIGHT_TAIL_PIN 45
#define SERVO_HORIZONTAL_CAMERA_PIN 36
#define SERVO_VERTICAL_CAMERA_PIN 39

class ServoControl {

  public:

    ServoControl();
    void updateServo(int command);

  private:

    Servo s_leftWing;
    Servo s_rightWing;
    Servo s_leftTail;
    Servo s_rightTail;
    Servo s_horCamera;
    Servo s_verCamera;

    int ver_pos = 90;
    int hor_pos = 90;

};