#include "HexdServos.hpp"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial servoSerial(10, 11); // RX, TX
HexdServos servos(10, 11, 9600);
const int servoDelay = 200;

void setup() { servos.begin(); }

void loop() {
  for (int i = 180; i >= 0; i -= 45) {
    servos.servoWrite(1, i);
    delay(servoDelay);
  }

  for (int i = 0; i < 180; i += 45) {
    servos.servoWrite(1, i);
    delay(servoDelay);
  }
}
