int dir1PinA = 9; // Motor Controller IN1
int dir2PinA = 8; // Motor Controller IN2
int speedPinA = 10; // EN 1

int IceMachine = 7; // IN 8
int pump1 = 6; // IN 7
int pump2 = 5; // IN 6
int pump3 = 4; // IN 5
int pump4 = 3; // IN 4
int pump5 = 2; // IN 3

int Lswitch = 7; // Holder right under switch part #1; Normally Open

bool AtHome = false;
int doOnce = 0;


void setup() {
  Serial.begin(1200); // Seting up for serial monitor
  
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  
  pinMode(Lswitch,INPUT); // Receiving input
  
  pinMode(IceMachine, OUTPUT);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  pinMode(pump4, OUTPUT);
  pinMode(pump5, OUTPUT);
  
  // Auto Start Pumps Deactivated
  digitalWrite(IceMachine, HIGH);
  digitalWrite(pump1, HIGH);
  digitalWrite(pump2, HIGH);
  digitalWrite(pump3, HIGH);
  digitalWrite(pump4, HIGH);
  digitalWrite(pump5, HIGH);
}

void loop() {
  
   if(Serial.available() > 0)
   {
     int inByte = Serial.read();

      switch(inByte)
      {
        case 'i':
          InitalizePumps();
          break;
        
        case 'd':
          ReturnHome();
          CupPosition();
          DispenseCup();
          IcePosition();
          DispenseIce();
          Optic1Position();
          PourShot();
          PumpPosition();
          break;
        
         default:
          break;
  
      }
   }
    
}

void InitalizePumps()
{
  digitalWrite(pump1, LOW);
  digitalWrite(pump2, LOW);
  digitalWrite(pump3, LOW);
  digitalWrite(pump4, LOW);
  digitalWrite(pump5, LOW);
  delay(3500);
  digitalWrite(pump1, HIGH);
  digitalWrite(pump2, HIGH);
  digitalWrite(pump3, HIGH);
  digitalWrite(pump4, HIGH);
  digitalWrite(pump5, HIGH);
}

void DispenseCup()
{
  
}

void PourShot()
{
  
}

void DispenseIce()
{
  digitalWrite(IceMachine, LOW);
  delay(350);
  digitalWrite(IceMachine, HIGH);
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

void QuaterCup()
{
  digitalWrite(pump1, LOW);
  delay(750);
  digitalWrite(pump1, HIGH);
}

void HalfCup()
{
  digitalWrite(pump1, LOW);
  delay(1750);
  digitalWrite(pump1, HIGH);
}

void ThreeQuaterCup()
{
  digitalWrite(pump1, LOW);
  delay(3000);
  digitalWrite(pump1, HIGH);
}
