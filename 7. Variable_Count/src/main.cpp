#include <Arduino.h>

int count = 0; //INT Variable Count aangemaakt en ingesteld op 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial port.
}

void loop() {
  // put your main code here, to run repeatedly:
  count = count + 1;
  Serial.println(count);
  delay(1000);
}