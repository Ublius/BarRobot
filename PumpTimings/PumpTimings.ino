int IceMachine = 7; // IN 8
int pump1 = 6; // IN 7
int pump2 = 5; // IN 6
int pump3 = 4; // IN 5
int pump4 = 3; // IN 4
int pump5 = 2; // IN 3


// LOW = on
// HIGH = off

void setup() {
  Serial.begin(1200);
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
        case 'o':
          digitalWrite(IceMachine, HIGH);
          digitalWrite(pump1, HIGH);
          digitalWrite(pump2, HIGH);
          digitalWrite(pump3, HIGH);
          digitalWrite(pump4, HIGH);
          digitalWrite(pump5, HIGH);
          Serial.println("ALL Pumps & Ice Machine Off");
          break;
  
        case 'i':
          InitalizePumps();
          break;

        case 'q':
          QuaterCup();
          break;

        case 'h':
          HalfCup();
          break;

        case '3':
          ThreeQuaterCup();
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
