#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 291
#define SERVOMAX 1839
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;

int runonce = 0;

void setup() 
{
 Serial.begin(1200);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(1000);


}

int angleToPulse(int ang){
   int pulse = map(ang,0, 360, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

int pulseWidth(int angle)
{
int pulse_wide, analog_value;
pulse_wide = map(angle, 0, 180, SERVOMIN, SERVOMAX);
analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
Serial.println(analog_value);
return analog_value;
}

void loop() {
//pwm.setPWM(0, 0, 0);
//delay(1000);
////pwm.setPWM(0, 4096, 0);
////delay(500);
//    pwm.setPWM(0, 0, angleToPulse(0));
//    delay(280);
//    pwm.setPWM(0,0,angleToPulse(70));
//   delay(320);

//pwm.setPWM(0,0,140);
//delay(500);

if(runonce = 0)
{
  pwm.setPWM(0,0,pulseWidth(140));
  pwm.setPWM(1,0,pulseWidth(70));
  runonce += 1;
}

//delay(500);
//pwm.setPWM(0,0,0);



}
