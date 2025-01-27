#include "SIM7600.h"

SIM7600* sim7600;

void setup() {
  Serial.begin(115200);
  sim7600 = new SIM7600();
}

void loop() {
  // sim7600->sendATCommand("AT+CGPSINFO");
  // // sim7600->sendATCommand("AT+CGNSPWR?");
  // sim7600->sendATCommand("AT+CGNSPWR=1");
  
  sim7600->postData();
  delay(1000);

  sim7600->commandServo();
  delay(1000);
}