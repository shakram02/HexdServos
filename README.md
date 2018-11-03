# HexdServos

Arduino library for 16/32 servo controller. The communication with the MCU on the controller is done using a software serial

** References are in the `attachements` folder **

![](attachments/controller_image.png)

## Usage

For easy usage, add the library using `Arduino` text editor (a.k.a IDE) from `Sketch->Include Library->Add .ZIP Library...`

- Create a HexdServos object
- Write the data to `servoNumber` giving it an `angle` and optionally a `speed`
- Angles range from `0~180`
- Speeds range from `0~100`

```Arduino
#include "HexdServos.hpp"
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
```
