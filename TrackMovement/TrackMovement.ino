int dir1PinA = 9;
int dir2PinA = 8;
int speedPinA = 10;
int Lswitch = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(Lswitch,INPUT);
}

void loop() {

    if(digitalRead(Lswitch) == HIGH)
    {
          Serial.println("running");
          analogWrite(speedPinA, 255);
          digitalWrite(dir1PinA, LOW);
          digitalWrite(dir2PinA, HIGH);
    }

    Serial.println("not running");
    analogWrite(speedPinA, 0);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, LOW);
    digitalWrite(Lswitch, HIGH); 
  // put your main code here, to run repeatedly:
//  if(Serial.available() > 0)
//  {
//    int inByte = Serial.read();
//    int speed;



//    switch (inByte)
//    {
//       case 's':
//        analogWrite(speedPinA, 0);
//        digitalWrite(dir1PinA, LOW);
//        digitalWrite(dir2PinA, LOW);
//    }
//  }

}
