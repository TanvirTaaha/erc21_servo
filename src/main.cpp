#include <Arduino.h>
#include <Servo.h>

#define srvpin 6 //pin 6 to control servo
#define SERVO_MIN_PULSE 1000
#define SERVO_MAX_PULSE 2000


Servo srv1;
long deg = 0;


void write_and_delay(int degree, int delayMilis) {
  int mapped = map(degree, 0, 270, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  //as it is a 270 degree servo we use writeMicroseconds
  srv1.writeMicroseconds(mapped);
  Serial.print("written:");
  Serial.println(mapped);
  Serial.print("degree:");
  Serial.println(degree);
  delay(delayMilis);
}

void setup()
{
  Serial.begin(9600);
  srv1.attach(srvpin);
  write_and_delay(0, 10); //intialize at zero degree
}

void loop()
{
  Serial.println("Enter a number from 0 - 270");
  while (Serial.available() == 0)
  {
    //wait until data channel is idle
  }

  deg = Serial.parseInt();
  Serial.read(); // to skip the enter key (if any)
  
  Serial.print("found deg:");
  Serial.println(deg);
  if (deg >= 0 && deg <= 270) // can not write more than 270 degree or less than 0
  {
    write_and_delay(deg, 500);
  }
  else
  {
    Serial.println("number is not between 0 - 270");
    delay(10);
  }
}
