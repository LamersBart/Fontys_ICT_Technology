#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_BLUE = 6;    // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial port.
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_LED_RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Rode LED aan");
  delay(1000);                       // wait for a second
  digitalWrite(PIN_LED_RED, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("Rode LED uit");
  delay(1000);                       // wait for a second
  digitalWrite(PIN_LED_BLUE, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Blauwe LED aan");
  delay(1000);                       // wait for a second
  digitalWrite(PIN_LED_BLUE, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("Blauwe LED uit");
  delay(1000);                       // wait for a second
}