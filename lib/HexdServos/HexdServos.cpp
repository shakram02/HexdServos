//
//  HexdServos.cpp
//  hexapod_servos
//
//  Created by <author> on 09/11/2017.
//
//

#include "HexdServos.hpp"

HexdServos::HexdServos(int rx, int tx, int baud_rate)
    : servoSerial(rx, tx), baud_rate(baud_rate) {}

void HexdServos::begin() { servoSerial.begin(baud_rate); }

void HexdServos::test() {
  servoSerial.print("#1P500T320\r\n");
  delay(1000);
  servoSerial.print("#1P2500T320\r\n");
  delay(1000);
}

HexdServos::~HexdServos() {}
