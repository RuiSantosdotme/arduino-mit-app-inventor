/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
 */

// include the library code:
#include <LiquidCrystal.h>

#define max_char 32
char message[max_char];    // stores you message
char r_char;               // reads each character
byte index = 0;            // defines the position into your array
int i;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  delay(1000);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //check if serial is available an before reading a new message delete's the old message
  if(Serial.available()){       
    for(i=0; i<31; i++){
      message[i] = '\0';
    } 
    //resests the index
    index=0;
  }
  //while is reading the message 
  while(Serial.available() > 0){
    //the message can have up to 100 characters 
    if(index < (max_char-1)){         
      r_char = Serial.read();      // Reads a character
      message[index] = r_char;     // Stores the character in message array
      index++;                     // Increment position
      message[index] = '\0';       // Delete the last position
   }
 }
 lcd.clear();
 lcd.print(message);
 
 // scroll up to 16 positions to the left
 // to move it offscreen left
 if(message[0]!= '\0'){
   for (int positionCounter = 0; positionCounter < index/2; positionCounter++) {
    delay(750);
    // scroll one position left:
    lcd.scrollDisplayLeft();
   }
 }
}
