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
        case 'h':
          digitalWrite(IceMachine, HIGH);
          digitalWrite(pump1, HIGH);
          digitalWrite(pump2, HIGH);
          digitalWrite(pump3, HIGH);
          digitalWrite(pump4, HIGH);
          digitalWrite(pump5, HIGH);
          Serial.println("ALL Pumps & Ice Machine Off");
          break;

        case '0':
          digitalWrite(IceMachine, LOW);
          Serial.println("Ice Machine On");
          break;
  
        case '1':
          digitalWrite(pump1, LOW);
          Serial.println("Pump 1 On");
          break;

        case '2':
          digitalWrite(pump2, LOW);
          Serial.println("Pump 2 On");
          break;

        case '3':
          digitalWrite(pump3, LOW);
          Serial.println("Pump 3 On");
          break;

        case '4':
          digitalWrite(pump4, LOW);
          Serial.println("Pump 4 On");
          break;

        case '5':
          digitalWrite(pump5, LOW);
          Serial.println("Pump 5 On");
          break;
  
          
         default:
          break;
  
      }
   }
}
