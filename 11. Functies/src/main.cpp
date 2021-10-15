#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;  // Keep track of the button 1 state.
int buttonState_2 = 0;  // Keep track of the button 1 state.
int lastButtonState_1 = 1;
int lastButtonState_2 = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
  pinMode(PIN_BUTTON_2, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void LedKnipper3() {
  buttonState_1 = digitalRead(PIN_BUTTON_1);
  if (buttonState_1 != lastButtonState_1) {
    if (buttonState_1 == LOW) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(PIN_LED_RED, HIGH);
        delay(500);
        digitalWrite(PIN_LED_RED, LOW);
        delay(500);
       }
    }
  }
  lastButtonState_1 = buttonState_1;
}

void LedKnipper5(int aantalKnipper) {
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  if (buttonState_2 != lastButtonState_2) {
    if (buttonState_2 == LOW) {
      for (int i = 0; i < aantalKnipper; i++) {
        digitalWrite(PIN_LED_RED, HIGH);
        delay(500);
        digitalWrite(PIN_LED_RED, LOW);
        delay(500);
       }
    }
  }
  lastButtonState_2 = buttonState_2;
}

void loop() {
  // put your main code here, to run repeatedly:
  LedKnipper3();
  LedKnipper5(5);
}