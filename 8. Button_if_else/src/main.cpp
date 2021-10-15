#include <Arduino.h>
const int PIN_LED_BLUE = 6; // The Number of the blue LED pin.
const int PIN_LED_RED = 4;   // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8; // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 2 (KEY2) pin.

int buttonState_1 = 0; // Keep track of the button 1 state.
int buttonState_2 = 0; // Keep track of the button 2 state.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Initialize serial port.
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
  pinMode(PIN_BUTTON_2, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState_1 = digitalRead(PIN_BUTTON_1);
  if (buttonState_1 == LOW)
    {
        // Turn the led on (the button is active LOW).
        digitalWrite(PIN_LED_BLUE, HIGH);
        Serial.println("button 1 pressed");
        Serial.println(buttonState_1);
        delay(200);
    }
    else
    {
        // Turn the led off.
        digitalWrite(PIN_LED_BLUE, LOW);
    }
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  if (buttonState_2 == LOW) //HIGH EN LOW GEBRUIKEN
    {
        // Turn the led on (the button is active LOW).
        digitalWrite(PIN_LED_RED, HIGH);
        Serial.println("button 2 pressed");
        delay(200);
    }
    else
    {
        // Turn the led off.
        digitalWrite(PIN_LED_RED, LOW);
    }  
}