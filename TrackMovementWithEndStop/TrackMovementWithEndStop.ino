int dir1PinA = 9; // Motor Controller IN1
int dir2PinA = 8; // Motor Controller IN2
int speedPinA = 10; // EN 1
int Lswitch = 2; // Holder right under switch part #1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200); // Seting up for serial monitor
  pinMode(dir1PinA,OUTPUT); // Outputing
  pinMode(dir2PinA,OUTPUT); // outpunt
  pinMode(speedPinA,OUTPUT);
  pinMode(Lswitch,INPUT); // recing input
}

void loop() {

    if(digitalRead(Lswitch) == HIGH) // Activates when switch is not being pressed
    {
          Serial.println("running");
          analogWrite(speedPinA, 255);
          digitalWrite(dir1PinA, HIGH);
          digitalWrite(dir2PinA, LOW);
    }

    if(digitalRead(Lswitch) == LOW) // Deactivates when switch is being pressed 
    { // remove this if statement if it does not works
      Serial.println("not running");
      analogWrite(speedPinA, 0);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
    }
    
    digitalWrite(Lswitch, HIGH); // Just needs this no idea why i think just activates it
}
