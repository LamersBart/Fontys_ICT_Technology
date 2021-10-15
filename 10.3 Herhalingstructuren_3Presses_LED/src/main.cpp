#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;        // Keep track of the button 1 state.
int lastButtonState = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonPressed = 0;
  while (buttonPressed < 3) {
    buttonState_1 = digitalRead(PIN_BUTTON_1);
    if (buttonState_1 != lastButtonState)
    {
      if (buttonState_1 == LOW)
      {
        buttonPressed++;
        delay(250);
      }
    }
    lastButtonState = buttonState_1;
  }
  digitalWrite(PIN_LED_RED, HIGH);

  while (buttonPressed < 6) {
    buttonState_1 = digitalRead(PIN_BUTTON_1);
      if (buttonState_1 != lastButtonState)
      {
        if (buttonState_1 == LOW)
        {
        buttonPressed++;
        delay(250);
        }
      } 
      lastButtonState = buttonState_1;      
  }
  digitalWrite(PIN_LED_RED, LOW);
}