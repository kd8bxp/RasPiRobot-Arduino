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
const long interval = 5000;
long duration;
int distance;

int fastspd = 50;
int mediumspd = 30;
int slowspd = 25;
int speed = 50; //percent of speed from 0 to 100 (0 stop, 100 full speed).

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
}

void loop() {

  updatePWM();
if (ping() > 15) {
  speed = fastspd;  
  forward();
  
} else {
  speed = slowspd;
  //turnLeft();
  turnRight();
    }
}

void updatePWM() {
  unsigned long currentmicro = micros();

  if (currentmicro - previousmicro >= interval) {
    // save the last time you blinked the LED
    previousmicro = currentmicro;

 pwm(RIGHT_PWM_PIN, speed);
 pwm(LEFT_PWM_PIN, speed);
 
  }
}

void forward() {
  //Forward Motion
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, HIGH);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, HIGH);
}

void backward() {
  //Backward Motion
  digitalWrite(LEFT_1_PIN, HIGH);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, HIGH);
  digitalWrite(RIGHT_2_PIN, LOW);
}

void turnLeft() {
  
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, HIGH);
  digitalWrite(RIGHT_1_PIN, HIGH);
  digitalWrite(RIGHT_2_PIN, LOW);
}

void turnRight() {
  
  digitalWrite(LEFT_1_PIN, HIGH);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, HIGH);
}

void stop() {
  
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, LOW);
  digitalWrite(RIGHT_1_PIN, LOW);
  digitalWrite(RIGHT_2_PIN, LOW);
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

