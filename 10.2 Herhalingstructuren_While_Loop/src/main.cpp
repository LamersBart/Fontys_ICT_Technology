#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;        // Keep track of the button 1 state.
int lastButtonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void loop() {
  // put your main code here, to run repeatedly:
  lastButtonState = buttonState_1;
  buttonState_1 = digitalRead(PIN_BUTTON_1);
  if (lastButtonState == HIGH && buttonState_1 == LOW)
  {
    int tellen = 0;
    while (tellen <= 2)
    {
      tellen++;
      
      digitalWrite(PIN_LED_RED, HIGH);
      delay(1000);
      digitalWrite(PIN_LED_RED, LOW);
      delay(1000);
    }
  }
}