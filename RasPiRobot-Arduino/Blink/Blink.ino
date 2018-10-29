int led1 = 8;
int led2 = 7;
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    delay(500);           // wait for a second
  digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    delay(500);                  // wait for a second
}
