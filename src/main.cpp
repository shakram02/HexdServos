#include "HexdServos.hpp"
#include <Arduino.h>

const int rxPin = 10;
const int txPin = 11;
const int servoDelay = 200;

HexdServos servos(rxPin, txPin, 9600);

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
