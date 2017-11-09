#include "HexdServos.hpp"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial servoSerial(10, 11); // RX, TX
HexdServos servos(10, 11, 9600);
void setup() { servos.begin(); }
void loop() { servos.test(); }
