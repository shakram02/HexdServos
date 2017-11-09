//
//  HexdServos.cpp
//  hexapod_servos
//
//  Created by Ahmed Hamdy (shakram02) on 09/11/2017.
//
//

#include "HexdServos.hpp"

HexdServos::HexdServos(int rx, int tx, int baud_rate)
    : servoSerial(rx, tx), baud_rate(baud_rate) {}

void HexdServos::begin() { servoSerial.begin(baud_rate); }

void HexdServos::servoWrite(int servoNum, int degree, int speedRate) {
  write(servoNum, degree, speedRate);
}

void HexdServos::servoWrite(int servoNum, int degree) {
  write(servoNum, degree, SERVO_SPEED_RATE_MAX);
}

void HexdServos::write(int servoNumber, int degree, int speed) {
  String servoNum = String(servoNumber);

  String servoLoc = String(mapAngle(degree));
  String servoSpeed = String(mapSpeed(speed));

  // Message format is specified by the datasheet
  // Format: # <ch> P <pw> ... # <ch> P <pw> T <time> \ n \ r
  // <ch> = Servo number, range 1~32 (decimal number)
  // <pw> = Pulse width (servo position), range: 500~2500. Unit: us
  // (microseconds) <time> = Time used to move to the position, effective for
  // all servos.
  String msg = String("#") + servoNum + String("P") + servoLoc + String("T") +
               servoSpeed + String("\r\n");

  servoSerial.print(msg);
}

long HexdServos::mapAngle(long x) {
  return this->map(x, SERVO_DEG_MIN, SERVO_DEG_MAX, SERVO_LOCATION_MIN,
                   SERVO_LOCATION_MAX);
}

long HexdServos::mapSpeed(long x) {
  return this->map(x, SERVO_SPEED_RATE_MIN, SERVO_SPEED_RATE_MAX,
                   SERVO_SPEED_MAX, SERVO_SPEED_MIN);
}

long HexdServos::map(long x, long inMin, long inMax, long outMin, long outMax) {
  // Longs are used as the numbers overflew the bound and produced really nasty
  // bugs, the map function in re-written here to reduce dependencies
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

HexdServos::~HexdServos() { servoSerial.end(); }
