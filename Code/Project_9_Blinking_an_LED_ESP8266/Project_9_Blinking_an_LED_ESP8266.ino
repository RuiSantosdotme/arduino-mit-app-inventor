/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

int pin = 2;

void setup() {
  // initialize GPIO 2 as an output.
  pinMode(pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on
  delay(1000);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off
  delay(1000);               // wait for a second
}
