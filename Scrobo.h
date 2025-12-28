#ifndef Scrobo_h
#define Scrobo_h
#include "Arduino.h"

#define M1PWM 5   // PWMA
#define M1IN1 8   // AIN1
#define M1IN2 7   // AIN2
#define M2PWM 6   // PWMB
#define M2IN1 11  // BIN1
#define M2IN2 12  // BIN2
#define M3PWM 9   // PWMA
#define M3IN1 2   // AIN1
#define M3IN2 4   // AIN2
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
};

#endif