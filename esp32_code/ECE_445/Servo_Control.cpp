#include "Servo_Control.h"

ServoControl::ServoControl() {
    s_leftWing.attach(SERVO_LEFT_WING_PIN);
    s_rightWing.attach(SERVO_RIGHT_WING_PIN);
    s_leftTail.attach(SERVO_LEFT_TAIL_PIN);
    s_rightTail.attach(SERVO_RIGHT_TAIL_PIN);
    s_horCamera.attach(SERVO_HORIZONTAL_CAMERA_PIN);
    s_verCamera.attach(SERVO_VERTICAL_CAMERA_PIN);

    // s_leftWing.write(90);
    // s_rightWing.write(90);
    // s_leftTail.write(90);
    // s_rightTail.write(90);
    // s_horCamera.write(hor_pos);
    // s_verCamera.write(ver_pos);
}

void ServoControl::updateServo(int command) {
    switch (command) {
        case -1:  // Reset all servos to neutral
            s_leftWing.write(90);
            s_rightWing.write(90);
            s_leftTail.write(90);
            s_rightTail.write(90);
            break;

        case 0:  // Vertical tail up
            s_leftWing.write(90);
            s_rightWing.write(90);
            s_leftTail.write(135);
            s_rightTail.write(135);
            break;

        case 1:  // Wings and tail in opposite directions
            s_leftWing.write(135);
            s_rightWing.write(45);
            s_leftTail.write(135);
            s_rightTail.write(45);
            break;

        case 2:  // Wings and tail in opposite directions (reversed)
            s_leftWing.write(45);
            s_rightWing.write(135);
            s_leftTail.write(45);
            s_rightTail.write(135);
            break;

        case 3:  // Vertical tail down
            s_leftWing.write(90);
            s_rightWing.write(90);
            s_leftTail.write(45);
            s_rightTail.write(45);
            break;

        case 4:  // Move vertical camera up
            for (int i = 0; i < 10; i += 2) {
                ver_pos = constrain(ver_pos + i, 45, 135);
                s_verCamera.write(ver_pos);
                delay(15);
            }
            break;

        case 5:  // Move horizontal camera right
            for (int i = 0; i < 10; i += 2) {
                hor_pos = constrain(hor_pos + i, 45, 135);
                s_horCamera.write(hor_pos);
                delay(15);
            }
            break;

        case 6:  // Move horizontal camera left
            for (int i = 0; i < 10; i += 2) {
                hor_pos = constrain(hor_pos - i, 45, 135);
                s_horCamera.write(hor_pos);
                delay(15);
            }
            break;

        case 7:  // Move vertical camera down
            for (int i = 0; i < 10; i += 2) {
                ver_pos = constrain(ver_pos - i, 45, 135);
                s_verCamera.write(ver_pos);
                delay(15);
            }
            break;

        default:  // Invalid command
            break;
    }
}
