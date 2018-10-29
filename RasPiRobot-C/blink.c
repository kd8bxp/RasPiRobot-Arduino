#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
int led1 = 10;
int led2 = 11;
  printf("Raspberry Pi wiringPi blink test\n");

  if (wiringPiSetup() == -1)
    exit (1);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  for (;;){
    printf("LED On\n");
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    delay(250);
    printf("LED Off\n");
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    delay(250);
  }

  return 0;
}
