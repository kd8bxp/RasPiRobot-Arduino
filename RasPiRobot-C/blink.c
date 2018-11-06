#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t flag = 0;
int led1 = 10;
int led2 = 11;

void catchC(int sig){ // can be called asynchronously
  flag = 1; // set flag
digitalWrite(led1, 0);
digitalWrite(led2, 0);
exit(1);
}

int main() {
signal(SIGINT, catchC); 

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
