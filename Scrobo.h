#ifndef Scrobo_h
#define Scrobo_h
#include "Arduino.h"

#define M1PWM 6
#define M1DIR 7
#define M2PWM 5
#define M2DIR 4
#define M3PWM 9
#define M3DIR 8
#define M4PWM 10
#define M4DIR 11
// STBY is set HIGH on the board

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
  void setSpeedM4(int speed);
};

#endif