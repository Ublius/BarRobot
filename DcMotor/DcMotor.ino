int dir1PinA = 9; // Motor Controller IN1
int dir2PinA = 10; // Motor Controller IN2
int speedPinA = 8; // EN 1

//Keyboard Controls:
//
// C - Clockwise
// S - Stop
// A - Anti-clockwise


void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    int inByte = Serial.read();
    int speed;

    switch (inByte)
    {
      case 'c': //Clockwise
      analogWrite(speedPinA, 255);//Sets speed variable via PWM 
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      Serial.println("Clockwise rotation"); // Prints out “Motor 1 Forward” on the serial monitor
      Serial.println("   "); // Creates a blank line printed on the serial
      break;

      case 's': //Stop
      analogWrite(speedPinA, 0);//Sets speed variable via PWM 
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      Serial.println("Stop"); // Prints out “Motor 1 Forward” on the serial monitor
      Serial.println("   "); // Creates a blank line printed on the serial
      break;

      case 'a': //Anti Clockwise
      analogWrite(speedPinA, 255); // Maximum PWM (speed)
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      Serial.println("Anti-clockwise rotation");
      Serial.println("   ");
      break;
       
       default:
        // Turn off the motor if any other key is being pressed
        break;
   }
  }
}
