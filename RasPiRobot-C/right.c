#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>
#include <sys/time.h>
#include <signal.h>

#define analogWrite softPwmWrite
#define RIGHT_PWM_PIN 15
#define RIGHT_1_PIN 12
#define RIGHT_2_PIN 6

void catchC(int sig){ // can be called asynchronously
analogWrite(RIGHT_PWM_PIN, 0);
digitalWrite(RIGHT_1_PIN, 0);
digitalWrite(RIGHT_2_PIN, 0);
exit(1);
}


int main(int argc, char* argv[]) {
signal(SIGINT, catchC); 

if (argc < 2) {
printf("use right time(in seconds) speed (1 to 100)\n\n");
return 0;
}

int time = atoi(argv[1]);
int spd = atoi(argv[2]);

if (spd <= 0 || spd > 100) {
printf("Speed must be between 1 and 100\n\n");
return 0;
}

  if (wiringPiSetup() == -1)
    exit (1);

softPwmCreate(RIGHT_PWM_PIN,0,100);
pinMode(RIGHT_1_PIN, OUTPUT);
pinMode(RIGHT_2_PIN, OUTPUT);

    analogWrite(RIGHT_PWM_PIN, spd);
    digitalWrite(RIGHT_1_PIN, HIGH);
    digitalWrite(RIGHT_2_PIN, LOW);

sleep(time);
analogWrite(RIGHT_PWM_PIN, 0);
digitalWrite(RIGHT_1_PIN, 0);
digitalWrite(RIGHT_2_PIN, 0);
  exit(0);
}
