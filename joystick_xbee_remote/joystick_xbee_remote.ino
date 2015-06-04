#include <SoftwareSerial.h>

#include <XBee.h>


// Store the Arduino pin associated with each input
const byte PIN_BUTTON_SELECT = 2; // Select button is triggered when joystick is pressed

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 4;
const byte PIN_BUTTON_DOWN = 5;
const byte PIN_BUTTON_LEFT = 6;

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

SoftwareSerial XBee(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);

  XBee.begin(9600);
  
  //    * HIGH = the button is not pressed
  //    * LOW = the button is pressed  
  pinMode(PIN_BUTTON_RIGHT, INPUT);  
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
  
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
  
  pinMode(PIN_BUTTON_DOWN, INPUT);  
  digitalWrite(PIN_BUTTON_DOWN, HIGH);
  
  pinMode(PIN_BUTTON_SELECT, INPUT);  
  digitalWrite(PIN_BUTTON_SELECT, HIGH);  
}


void loop() {
  // Print the current values of the inputs (joystick and
  // buttons) to the console.
  if (digitalRead(PIN_BUTTON_LEFT) == 0) {
    Serial.print("left button pressed");
    Serial.println();
  }
  if (digitalRead(PIN_BUTTON_RIGHT) == 0) {
    Serial.print("right button pressed");
    Serial.println();
  }
  if (digitalRead(PIN_BUTTON_UP) == 0) {
    Serial.print("up button pressed");
    Serial.println();
  }
  if (digitalRead(PIN_BUTTON_DOWN) == 0) {
    Serial.print("down button pressed");
    Serial.println();
  }
  if ((analogRead(PIN_ANALOG_X) < 500) || (analogRead(PIN_ANALOG_X) > 550)) {
    Serial.print(analogRead(PIN_ANALOG_X));
    Serial.println();
  }
  if ((analogRead(PIN_ANALOG_Y) < 500) || (analogRead(PIN_ANALOG_Y) > 550)) {
    Serial.print(analogRead(PIN_ANALOG_Y));
    Serial.println();
  }
  if (digitalRead(PIN_BUTTON_SELECT) == 0) {
    Serial.print("joystick button pressed");
    Serial.println();
  }
  
  if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    XBee.write(Serial.read());
  }
  if (XBee.available())
  { // If data comes in from XBee, send it out to serial monitor
    Serial.write(XBee.read());
  }
}

