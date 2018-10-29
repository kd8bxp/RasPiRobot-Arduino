#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>

#define analogWrite softPwmWrite
#define RIGHT_PWM_PIN 15
#define RIGHT_1_PIN 12
#define RIGHT_2_PIN 6

int main() {

  if (wiringPiSetup() == -1)
    exit (1);

softPwmCreate(RIGHT_PWM_PIN,0,100);
pinMode(RIGHT_1_PIN, OUTPUT);
pinMode(RIGHT_2_PIN, OUTPUT);

  for (;;){

    analogWrite(RIGHT_PWM_PIN, 25);
    digitalWrite(RIGHT_1_PIN, HIGH);
    digitalWrite(RIGHT_2_PIN, LOW);
  }

  return 0;
}
