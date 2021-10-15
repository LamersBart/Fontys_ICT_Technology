#include <Arduino.h>

/*
 * Rich shield Hello World example
 * Adapted from Rich Shield Example Code
 * Name:
 * Date: 07/02/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>, modified to RichShieldHelloWorld by Rene Bakx 07/01/2021.
 * Version: 1.0
 */

#include "Display.h"

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_LED_BLUE = 6;   // The Number of the blue LED pin.
const int PIN_LED_YELLOW = 7; // The Number of the yellow LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 2 (KEY2) pin.

int buttonState_1 = 0; // Keep track of the button 1 state.
int buttonState_2 = 0; // Keep track of the button 2 state.

void setup()
{
    Serial.begin(9600); // Initialize serial port.
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);
    pinMode(PIN_LED_YELLOW, OUTPUT);
    pinMode(PIN_BUTTON_1, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 
    pinMode(PIN_BUTTON_2, INPUT_PULLUP); // Internal pullup as there is no pullup resistor on the Rich Shield. 

    // At startup, switch on two LEDs and show a number on the 4 digit display.
    // Also print 'Hello World!' to the Serial Monitor.
    digitalWrite(PIN_LED_RED, HIGH);
    digitalWrite(PIN_LED_GREEN, HIGH);
    Display.show("1234");
    Serial.println("Hello World!");
}

void loop()
{
    // Read the state of the button.
    buttonState_1 = digitalRead(PIN_BUTTON_1);
    buttonState_2 = digitalRead(PIN_BUTTON_2);

    if (buttonState_1 == LOW)
    {
        // Turn the led on (the button is active LOW).
        digitalWrite(PIN_LED_BLUE, HIGH);
    }
    else
    {
        // Turn the led off.
        digitalWrite(PIN_LED_BLUE, LOW);
    }

    if (buttonState_2 == LOW)
    {
        // turn the led on (the button is active LOW)
        digitalWrite(PIN_LED_YELLOW, HIGH);
    }
    else
    {
        // turn the led off.
        digitalWrite(PIN_LED_YELLOW, LOW);
    }
}