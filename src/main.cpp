#include <Arduino.h>
#include <Servo.h>

#define srvpin 6

Servo srv1;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  srv1.attach(srvpin);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 270; i++)
  {
    srv1.write(i);
    delay(10);
  }
  for (int i = 270; i > 0; i--)
  {
    srv1.write(i);
    delay(10);
  }
}