/*
  Scrobo.cpp - Library for Jikken 1, Theme 3.
  Created by Kunihisa Okano, February 22, 2025.
*/
#include "Arduino.h"
#include "Scrobo.h"

Scrobo::Scrobo() {
}

void Scrobo::begin(){
  // Set pin modes
  pinMode(M1DIR, OUTPUT);
  pinMode(M2DIR, OUTPUT);
  pinMode(M3DIR, OUTPUT);

  // pinMode(IRL, INPUT);
  // pinMode(IRC, INPUT);
  // pinMode(IRR, INPUT);
  // pinMode(DIST, INPUT);
  // pinMode(FLL, INPUT);
  // pinMode(FLR, INPUT);
}

void Scrobo::motorSpeed(int m, int speed){
    int pinDir;
    int pinPWM;
    switch (m){
    case 1:
        pinDir = M1DIR;
        pinPWM = M1PWM;
        break;

    case 2:
        pinDir = M2DIR;
        pinPWM = M2PWM;
        break;

    default:
        pinDir = M3DIR;
        pinPWM = M3PWM;
        break;
    }
    if (speed < 0){
        digitalWrite(pinDir, HIGH); // CCW
        speed = (-1) * speed;
    }else{
        digitalWrite(pinDir, LOW); // CW
    }
    if (speed > MAXDUTY){
        speed = MAXDUTY;
    }
    analogWrite(pinPWM, speed);
}

void Scrobo::setSpeedM1(int speed){
  motorSpeed(1, speed);
}

void Scrobo::setSpeedM2(int speed){
  motorSpeed(2, speed);
}

void Scrobo::setSpeedM3(int speed){
  motorSpeed(3, speed);
}
