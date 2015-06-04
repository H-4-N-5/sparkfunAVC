

int incomingByte;      // a variable to read incoming serial data into

int leftmotorForward = 8; // pin 8 --- left motor (+) green wire
int leftmotorBackward = 11; // pin 11 --- left motor (-) black wire
int leftMotorSpeedPin = 9; // pin 9 --- left motor speed signal

int rightmotorForward = 12; // pin 12 --- right motor (+) green wire
int rightmotorBackward = 13; // pin 13 --- right motor (-) black
int rightMotorSpeedPin = 10; // pin 10 --- right motor speed signal

int leftMotorSpeed = 0;
int rightMotorSpeed = 0;

int turnPotVal = 255;       // variable to store the value coming from the sensor
int turnPotVal2 = 255;

void setup() 
{ 
  pinMode(leftmotorForward, OUTPUT);
  pinMode(leftmotorBackward, OUTPUT);
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightmotorForward, OUTPUT);
  pinMode(rightmotorBackward, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  /*
  if(!Serial) {
    while(1);
  }*/
  
    while (Serial.available() > 0) {
  
      // look for the next valid integer in the incoming serial stream:
      turnPotVal = Serial.parseInt();
       
      turnPotVal2 = Serial.parseInt();
   
      rightMotorSpeed = (1023-turnPotVal)/4;
      
      leftMotorSpeed = turnPotVal2/4;
      
      analogWrite(leftMotorSpeedPin,leftMotorSpeed); //Enable left motor by setting speed
      analogWrite(rightMotorSpeedPin,rightMotorSpeed); //Enable left motor by setting speed
      
      digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage
      digitalWrite(rightmotorBackward,LOW);
      
      digitalWrite(leftmotorForward,HIGH);
      digitalWrite(rightmotorForward,HIGH);
      
    }
 
  
} 

