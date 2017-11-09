//
//  HexdServos.hpp
//  hexapod_servos
//
//  Created by Ahmed Hamdy (shakram02) on 09/11/2017.
//  Abstracts a 16/24 servo controller
//

#ifndef HexdServos_hpp
#define HexdServos_hpp

#include <Arduino.h>
#include <SoftwareSerial.h>

class HexdServos {

public:
  HexdServos(int rx, int tx, int baudRate);

  void begin();

  void servoWrite(int servoNum, int degree);
  void servoWrite(int servoNum, int degree, int speedRate);

  ~HexdServos();

protected:
private:
  SoftwareSerial _servoSerial;
  int _baud_rate;

  // User location input will be in degrees
  const long SERVO_DEG_MIN = 0;
  const long SERVO_DEG_MAX = 180;

  // User speed input will be in percentage (0~100)%
  const long SERVO_SPEED_RATE_MIN = 0;
  const long SERVO_SPEED_RATE_MAX = 100;

  // The locations range is 500-2500 as in the datasheet
  const long SERVO_LOCATION_MIN = 500;
  const long SERVO_LOCATION_MAX = 2500;

  // The speed range in 100-9999 as in the datasheet
  const long SERVO_SPEED_MIN = 100;
  const long SERVO_SPEED_MAX = 9999;

  void write(int servoNumber, int degree, int speed);

  long mapAngle(long x);
  long mapSpeed(long x);
  long map(long x, long inMin, long inMax, long outMin, long outMax);
};

#endif /* HexdServos_hpp */
