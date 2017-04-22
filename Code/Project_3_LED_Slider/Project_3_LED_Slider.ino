/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
 */

int ledPWM = 11;

int state;
int flag = 0; //makes sure that the serial only prints once the state


void setup() {
  // sets the pin as output:
  pinMode(ledPWM, OUTPUT);
  analogWrite(ledPWM, LOW);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //if some date is sent, reads it and saves in state
  if (Serial.available() > 0) {
    state = Serial.read();
    flag = 0;
  }
  if (flag == 0) {
    analogWrite(ledPWM, state);
    flag = 1;
  }
}
