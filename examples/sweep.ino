#include <HexdServos.hpp>
#include <Arduino.h>

const int rxPin = 10;
const int txPin = 11;
const int servoChannel = 1;
const int servoDelay = 200;
const int driverBaudRate = 9600;

HexdServos servos(rxPin, txPin, driverBaudRate);

void setup() { servos.begin(); }

void loop() {

  // Sweep counter-clockwise
  for (int i = 180; i >= 0; i -= 45) {
    servos.servoWrite(servoChannel, i);
    delay(servoDelay);
  }

  // Sweep clockwise
  for (int i = 0; i < 180; i += 45) {
    servos.servoWrite(servoChannel, i);
    delay(servoDelay);
  }
}
