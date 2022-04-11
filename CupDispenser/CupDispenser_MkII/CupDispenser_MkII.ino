#include <Servo.h>
Servo LeftMotor; //Servo 1
Servo myservo2; //Servo 2
int donceOnce = 0;

void setup() {
  LeftMotor.attach(7); //Servo 1 attached to pin 7; The Left Motor when your facing towards it
  myservo2.attach(8); //Servo 2 attached to pin 8
}
void loop() {
//    delay(1000); //wait 1s
//    LeftMotor.write(140); 
//if(donceOnce = 0)
//{
    myservo2.write(25); //Pull cup back
    delay(1000);
    myservo2.write(95); //push cup forwards 
    donceOnce = 1;
//}
//    delay(1000); //wait 1s
//    LeftMotor.write(70); 
//    myservo2.write(95); //push cup forwards              
}
