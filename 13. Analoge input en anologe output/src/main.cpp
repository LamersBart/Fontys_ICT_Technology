#include <Arduino.h>

const int PIN_LED_GREEN = 5;  // The Number of the red LED pin.
int analogPin = A0;           // potentiometer connected to analog pin 14
int val = 0;                  // variable to store the read value

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop()
{
  val = analogRead(analogPin);        // read the input pin
  Serial.println(val);
  analogWrite(PIN_LED_GREEN, val/4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}
