/*
CopyLEFT (c) 2018 LeRoy Miller

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

void setup() {

  pinMode(LEFT_PWM_PIN, OUTPUT);
  pinMode(LEFT_1_PIN, OUTPUT);
  pinMode(LEFT_2_PIN, OUTPUT);

}

void loop() {

 //del = analogRead(Ain)*15.625;
  int del = 2000; //This is the PWM from 0 to 16000
 pwm(LEFT_PWM_PIN, del);
 //Forward Motion
  digitalWrite(LEFT_1_PIN, LOW);
  digitalWrite(LEFT_2_PIN, HIGH);

//Can not use delay - always need to call the PWM function

}

void pwm(int pin, int del){
 
 digitalWrite(pin, HIGH);
 delayMicroseconds(del);
 digitalWrite(pin, LOW);
 delayMicroseconds(16000 - del);
}

