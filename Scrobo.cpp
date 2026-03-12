/*
 * Scrobo.cpp - Library for Jikken 1, Theme 3.
 * @author K. Okano
 */
#include "Scrobo.h"

Scrobo::Scrobo() {}

void Scrobo::begin() {
  // Set pin modes
  pinMode(M1DIR, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2DIR, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  pinMode(M3DIR, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  pinMode(M4DIR, OUTPUT);
  pinMode(M4PWM, OUTPUT);
  // Stop motors
  analogWrite(M1PWM, 0);
  analogWrite(M2PWM, 0);
  analogWrite(M3PWM, 0);
  analogWrite(M4PWM, 0);

  // pinMode(IRL, INPUT);
  // pinMode(IRC, INPUT);
  // pinMode(IRR, INPUT);
  // pinMode(DIST, INPUT);
  // pinMode(FLL, INPUT);
  // pinMode(FLR, INPUT);
}

void Scrobo::motorSpeed(int m, int speed) {
  int pinDir;
  int pinPWM;
  if (m == 1) {
    pinDir = M1DIR;
    pinPWM = M1PWM;
  } else if (m == 2) {
    pinDir = M2DIR;
    pinPWM = M2PWM;
  } else if (m == 3) {
    pinDir = M3DIR;
    pinPWM = M3PWM;
  } else if (m == 4) {
    pinDir = M4DIR;
    pinPWM = M4PWM;
  } else {
    return;
  }

  // if (speed == 0) {
  //   digitalWrite(pinDir, HIGH);  // STOP
  //   analogWrite(pinPWM, 0);
  //   return;
  // }
  if (speed < 0) {
    digitalWrite(pinDir, HIGH);  // CCW
    speed = -speed;
  } else {
    digitalWrite(pinDir, LOW);  // CW
  }
  if (speed > MAXDUTY) {
    speed = MAXDUTY;
  }
  analogWrite(pinPWM, speed);
}

void Scrobo::setSpeedM1(int speed) { motorSpeed(1, speed); }
void Scrobo::setSpeedM2(int speed) { motorSpeed(2, speed); }
void Scrobo::setSpeedM3(int speed) { motorSpeed(3, speed); }
void Scrobo::setSpeedM4(int speed) { motorSpeed(4, speed); }
