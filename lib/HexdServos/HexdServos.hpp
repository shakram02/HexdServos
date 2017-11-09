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

  // A rough estimation of the time needed for the servo to move
  // according to the datasheet, the servo moves 60degs. in 100msecs
  // I'll assume the worst case motion, and as I don't really know what
  // this timing does, maybe it makes the controller wait until
  // the motion is done then we must wait all the intervial to avoid
  // inconsistent states or whatever.
  // The worst case is that the servo is moving 180 degs. This takes 300msecs
  // TODO: Ability to change servo motion time
  const String SERVO_DELAY = "100";

  void write(int servoNumber, int degree, int speed);

  long mapAngle(long x);
  long mapSpeed(long x);
  long map(long x, long inMin, long inMax, long outMin, long outMax);

public:
  HexdServos(int rx, int tx, int baudRate);

  void begin();

  void servoWrite(int servoNum, int degree);
  void servoWrite(int servoNum, int degree, int speedRate);

  ~HexdServos();

protected:
};

#endif /* HexdServos_hpp */
