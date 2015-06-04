int leftKnob = A1;    // select the input pin for the potentiometer
int leftKnobValue = 0;  // variable to store the value coming from the sensor
int rightKnob = A2;    // select the input pin for the potentiometer
int rightKnobValue = 0;  // variable to store the value coming from the sensor

void setup() {
   Serial.begin(9600); 
}

void loop() {
  leftKnobValue = analogRead(leftKnob);  
  rightKnobValue = analogRead(rightKnob);  
  Serial.println(leftKnobValue);  
  Serial.println(rightKnobValue);    
  delay(50);                  
}
