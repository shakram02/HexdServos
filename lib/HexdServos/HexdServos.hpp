//
//  HexdServos.hpp
//  hexapod_servos
//
//  Created by <author> on 09/11/2017.
//
//

#ifndef HexdServos_hpp
#define HexdServos_hpp

#include <Arduino.h>
#include <SoftwareSerial.h>

class HexdServos {
private:
  SoftwareSerial servoSerial;
  int baud_rate;

public:
  HexdServos(int rx, int tx, int baud_rate);

  void begin();
  void test();

  ~HexdServos();

protected:
};

#endif /* HexdServos_hpp */
