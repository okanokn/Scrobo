/*
 * Scrobo.cpp - Library for Jikken 1, Theme 3.
 * @author K. Okano
 */
#include "Scrobo.h"

Scrobo::Scrobo() {}

void Scrobo::begin() {
  // Set pin modes
  pinMode(M1IN1, OUTPUT);
  pinMode(M1IN2, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2IN1, OUTPUT);
  pinMode(M2IN2, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  pinMode(M3IN1, OUTPUT);
  pinMode(M3IN2, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  // Stop motors
  analogWrite(M1PWM, 0);
  analogWrite(M2PWM, 0);
  analogWrite(M3PWM, 0);

  // pinMode(IRL, INPUT);
  // pinMode(IRC, INPUT);
  // pinMode(IRR, INPUT);
  // pinMode(DIST, INPUT);
  // pinMode(FLL, INPUT);
  // pinMode(FLR, INPUT);
}

void Scrobo::motorSpeed(int m, int speed) {
  int pinDir1;
  int pinDir2;
  int pinPWM;
  if (m == 1) {
    pinDir1 = M1IN1;
    pinDir2 = M1IN2;
    pinPWM = M1PWM;
  } else if (m == 2) {
    pinDir1 = M2IN1;
    pinDir2 = M2IN2;
    pinPWM = M2PWM;
  } else if (m == 3) {
    pinDir1 = M3IN1;
    pinDir2 = M3IN2;
    pinPWM = M3PWM;
  } else {
    return;
  }

  if (speed == 0) {
    digitalWrite(pinDir1, HIGH);  // STOP
    digitalWrite(pinDir2, HIGH);
    analogWrite(pinPWM, 0);
    return;
  }
  if (speed < 0) {
    digitalWrite(pinDir1, LOW);   // CCW
    digitalWrite(pinDir2, HIGH);  // CCW
    speed = -speed;
  } else {
    digitalWrite(pinDir1, HIGH);  // CW
    digitalWrite(pinDir2, LOW);   // CW
  }
  if (speed > MAXDUTY) {
    speed = MAXDUTY;
  }
  analogWrite(pinPWM, speed);
}

void Scrobo::setSpeedM1(int speed) { motorSpeed(1, speed); }
void Scrobo::setSpeedM2(int speed) { motorSpeed(2, speed); }
void Scrobo::setSpeedM3(int speed) { motorSpeed(3, speed); }
