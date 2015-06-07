#include <PID_v1.h>

#include <Servo.h>
#include <SoftwareSerial.h>



//double Setpoint_Theta, Input_Theta;
//PID ThetaPID();
//PID DeltaPID();

SoftwareSerial XBee(2, 3); // RX, TX
Servo myservo;

void setup()
{
  XBee.begin(9600);
  Serial.begin(9600);
  myservo.attach(9);
  myservo.writeMicroseconds(1500);
  Serial.println("initialize");
}

void loop()
{
  
 //check for serial signal and use it too controll servo
  while (Serial.available() > 0){
    
    int value = Serial.parseInt();
    
    int pwm = map(value, 0, 90, 1300, 1900);
    
    //Serial.print("microseconds");
    //Serial.println(pwm);
    
    myservo.writeMicroseconds(pwm); 
    
  }
     
 
}
