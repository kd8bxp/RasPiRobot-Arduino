/*
Copyright (c) 2018 LeRoy Miller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

//Arduino uses GPIO Pin number system
#define LEFT_PWM_PIN 24
#define LEFT_1_PIN 17
#define LEFT_2_PIN 4
#define RIGHT_PWM_PIN 14
#define RIGHT_1_PIN 10
#define RIGHT_2_PIN 25
#define TRIGGER_PIN 18
#define ECHO_PIN 23

unsigned long previousmicro = 0;
unsigned long previousMillis = 0;
const long interval = 5000;
long duration;
int distance;
long onTime;

//percent of speed from 0 to 100 (0 stop, 100 full speed)
int fastspd = 75;
int mediumspd = 40;
int slowspd = 20;

int currentSpeed;
int isrunning = 0;

void setup() {

  Serial.begin(9600);
  pinMode(LEFT_PWM_PIN, OUTPUT);
  pinMode(LEFT_1_PIN, OUTPUT);
  pinMode(LEFT_2_PIN, OUTPUT);
  pinMode(RIGHT_PWM_PIN, OUTPUT);
  pinMode(RIGHT_1_PIN, OUTPUT);
  pinMode(RIGHT_2_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  stop();
  pwm(RIGHT_PWM_PIN,0);
  pwm(LEFT_PWM_PIN,0);
  delay(1000);
  
}

void loop() {

  update();
  speed(mediumspd); //first run this doesn't work (?)  
  onTime = 500;
  forward();
  //forward();
  while (isrunning) {
    update();
  }
  onTime = 250;
  speed(mediumspd);
  turnLeft();
  while (isrunning) {
    update();
  }
  onTime = 500;
  speed(mediumspd);
  turnRight();
  while (isrunning) {
    update();
  }
  onTime = 250;
  speed(mediumspd);
  turnLeft();
  while (isrunning) {
    update();
  }
  onTime = 500;
  speed(mediumspd);
  backward();
  while (isrunning) {
    update();  
  }
 stop();
 delay(2000);
update();

}

void speed(int spd) {
  pwm(RIGHT_PWM_PIN,spd);
  pwm(LEFT_PWM_PIN, spd);
  currentSpeed = spd;
}

void update() {
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= onTime) {
    previousMillis = currentMillis;
    stop();
    pwm(RIGHT_PWM_PIN, 0);
    pwm(LEFT_PWM_PIN, 0);
  }
updatePWM();
}  


void updatePWM() {
  unsigned long currentmicro = micros();

  if (currentmicro - previousmicro >= interval) {
       previousmicro = currentmicro;
 pwm(RIGHT_PWM_PIN, currentSpeed);
 pwm(LEFT_PWM_PIN, currentSpeed);
 
  }
}


void forward() {
  //Forward Motion
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, HIGH);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, HIGH);
  isrunning = 1;
}

void backward() {
  //Backward Motion
  digitalWrite(LEFT_1_PIN, HIGH);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, HIGH);
  digitalWrite(RIGHT_2_PIN, LOW);
  isrunning = 1;
}

void turnLeft() {
  
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, HIGH);
  digitalWrite(RIGHT_1_PIN, HIGH);
  digitalWrite(RIGHT_2_PIN, LOW);
  isrunning = 1;
}

void turnRight() {
  
  digitalWrite(LEFT_1_PIN, HIGH);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, HIGH);
  isrunning = 1;
}

void stop() {
  
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, LOW);
  currentSpeed = 0;
  isrunning = 0;
}

void pwm(int pin, int del){
 int spd = map(del,0, 100, 0, 16000); //set speed percent to a PWM from 0 to 16000
 digitalWrite(pin, HIGH);
 delayMicroseconds(spd);
 digitalWrite(pin, LOW);
 delayMicroseconds(16000 - spd);
}

int ping() {
  
digitalWrite(TRIGGER_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH);
distance= duration*0.034/2;
//Serial.print("Distance: ");
//Serial.println(distance);
if (distance > 1000) { distance = 0; }
return distance;
}

