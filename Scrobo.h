#ifndef Scrobo_h
#define Scrobo_h
#include "Arduino.h"

#define M1PWM 5  //INA
#define M1DIR 4  //INB
#define M2PWM 6  //INA
#define M2DIR 7  //INB
#define M3PWM 9  //INA
#define M3DIR 8  //INB

// #define IRL A0
// #define IRC A1
// #define IRR A2
// #define DIST A3
// #define FLL A6
// #define FLR A7

#define MAXDUTY 255

class Scrobo {
  public:
    Scrobo();
    void begin();
    void motorSpeed(int m, int speed);
    void setSpeedM1(int speed);
    void setSpeedM2(int speed);
    void setSpeedM3(int speed);
};

#endif