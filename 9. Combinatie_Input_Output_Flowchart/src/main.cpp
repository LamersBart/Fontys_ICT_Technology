#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_LED_BLUE = 6;   // The Number of the blue LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;  // Keep track of the button 1 state.
int buttonState_2 = 0;  // Keep track of the button 1 state.
int lampCount = 0;      // Variable om te tellen welke LED aan moet
int richting = 1;


void setup() {
  // put your setup code here, to run once:
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);
    pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
    pinMode(PIN_BUTTON_2, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void loop() {
  buttonState_1 = digitalRead(PIN_BUTTON_1);
  if (buttonState_1 == LOW)
  {
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_BLUE, LOW);
    if (lampCount == 1) {
      digitalWrite(PIN_LED_RED, HIGH);
      delay(250);
    }
    if (lampCount == 2) {
      digitalWrite(PIN_LED_GREEN, HIGH);
      delay(250);
    }
    if (lampCount == 3) {
      digitalWrite(PIN_LED_BLUE, HIGH);
      delay(250);
    }
    
    lampCount = lampCount + richting;

    if (lampCount >= 4 && richting == 1) {
      lampCount = 0;
    }
    if (lampCount <= 0 && richting == -1) {
      lampCount = 4;
    }
  }
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  if (buttonState_2 == LOW && richting == 1) {
    richting = -1;
    delay(500);
  }
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  if (buttonState_2 == LOW && richting == -1) {
    richting = 1;
    delay(500);
  }
} //insprining accolades