int dir1PinA = 9; // Motor Controller IN1
int dir2PinA = 10; // Motor Controller IN2
int speedPinA = 8; // EN 1
int Lswitch = 11; // Holder right under switch part #1; Normally Open
bool AtHome = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200); // Seting up for serial monitor
  pinMode(dir1PinA,OUTPUT); // Outputing
  pinMode(dir2PinA,OUTPUT); // outpunt
  pinMode(speedPinA,OUTPUT);
  pinMode(Lswitch,INPUT); // recing input
}

void loop() {
 AtHome = false;
 if(Serial.available() > 0)
  {
    int inByte = Serial.read();

    switch(inByte)
    {
      case 'h': // Home
        ReturnHome();
        break;

      case '1': // Cup Position
        CupPosition();
        break;
        
      case '2': // Ice Position
        IcePosition();
        break;
        
      case '3': // Optic 1 Positon
        Optic1Position();
        break;

      case '4': // Optic 2 Positon
        Optic2Position();
        break;
        
      case '5': // Optic 3 Positon
        Optic3Position();
        break;

      case '6': // Optic 4 Positon
        Optic4Position();
        break;

      case '7': // Optic 5 Positon
        Optic5Position();
        break;

      case '8': // Optic 6 Positon
        Optic6Position();
        break;

      case '9': // Pump Positon
        PumpPosition();
        break;
        
//      default:
////        StopMotor();
//        break;
    }
  }
//    if(digitalRead(Lswitch) == HIGH) // Activates when switch is not being pressed
//    {
//          Serial.println("running");
//          analogWrite(speedPinA, 255);
//          digitalWrite(dir1PinA, LOW);
//          digitalWrite(dir2PinA, HIGH);
//    }
//
//    if(digitalRead(Lswitch) == LOW) // Deactivates when switch is being pressed 
//    { // remove this if statement if it does not works
//      Serial.println("not running");
//      analogWrite(speedPinA, 0);
//      digitalWrite(dir1PinA, HIGH);
//      digitalWrite(dir2PinA, LOW);
//    }
//    
//    digitalWrite(Lswitch, HIGH); // Just needs this no idea why i think just activates it
}

void StopMotor()
{
  analogWrite(speedPinA, 0);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
}

void MoveForward()
{
  analogWrite(speedPinA, 255);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
}

void MoveBackward()
{
  analogWrite(speedPinA, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
}

void ReturnHome()
{
  if(digitalRead(Lswitch) == LOW) // Activates when switch is not being pressed
  {
    Serial.println("Returning Home");
    MoveBackward();
   }
  Serial.println("Returned Home");
  AtHome = true;
}

void CupPosition()
{
  AtHome = false;
  Serial.println("Going to Cup Position");
  MoveForward();
  delay(165);
  StopMotor();
  Serial.println("At Cup Position");
}

void IcePosition()
{
  AtHome = false;
  Serial.println("Going to Ice Position");
  MoveForward();
  delay(640);
  StopMotor();
  Serial.println("At Ice Position");
}

void Optic1Position()
{
  AtHome = false;
  Serial.println("Going to Optic 1 Position");
  MoveForward();
  delay(520);
  StopMotor();
  Serial.println("At Optic 1 Position");
}

void Optic2Position()
{
  AtHome = false;
  Serial.println("Going to Optic 2 Position");
  MoveForward();
  delay(300);
  StopMotor();
  Serial.println("At Optic 2 Position");
}

void Optic3Position()
{
  AtHome = false;
  Serial.println("Going to Optic 3 Position");
  MoveForward();
  delay(310);
  StopMotor();
  Serial.println("At Optic 3 Position");
}

void Optic4Position()
{
  AtHome = false;
  Serial.println("Going to Optic 4 Position");
  MoveForward();
  delay(310);
  StopMotor();
  Serial.println("At Optic 4 Position");
}

void Optic5Position()
{
  AtHome = false;
  Serial.println("Going to Optic 5 Position");
  MoveForward();
  delay(335);
  StopMotor();
  Serial.println("At Optic 5 Position");
}

void Optic6Position()
{
  AtHome = false;
  Serial.println("Going to Optic 6 Position");
  MoveForward();
  delay(310);
  StopMotor();
  Serial.println("At Optic 6 Position");
}

void PumpPosition()
{
  AtHome = false;
  Serial.println("Going to Pump Position");
  MoveForward();
  delay(345);
  StopMotor();
  Serial.println("At Pump Position");
}
