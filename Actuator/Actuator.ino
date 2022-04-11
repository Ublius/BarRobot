int dir1PinA = 9; // Actuator Controller IN1
int dir2PinA = 10; // Actuator Controller IN2

//Keyboard Controls:
// O - Out
// I - In


void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    int inByte = Serial.read();
    int speed;

    switch (inByte)
    {
      case 'o': // Acutator Out
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      Serial.println("Acutator Out"); // Prints out “Motor 1 Forward” on the serial monitor
      Serial.println("   "); // Creates a blank line printed on the serial
      break;

      case 'i': // Actuator In
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      Serial.println("Actuator In");
      Serial.println("   ");
      break;
       
       default:
        // Turn off the motor if any other key is being pressed
        break;
   }
  }
}
