#include <Arduino.h>

const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_LED_BLUE = 6;    // The Number of the red LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;        // Keep track of the button 1 state.
int buttonState_2 = 0;        // Keep track of the button 1 state.
int lastButtonState_1 = 1;
int lastButtonState_2 = 1;
int my_array[8];
int teller = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP); 
  pinMode(PIN_BUTTON_2, INPUT_PULLUP); 
}

void button1()
{
  buttonState_1 = digitalRead(PIN_BUTTON_1);
    if (lastButtonState_1 != buttonState_1)
    {
      if (buttonState_1 == LOW)
        {
          my_array[teller] = 1;
          teller++;
          delay(250);
        }
    }
    lastButtonState_1 = buttonState_1;
}

void button2()
{
  buttonState_2 = digitalRead(PIN_BUTTON_2);
    if (lastButtonState_2 != buttonState_2)
    {
      if (buttonState_2 == LOW)
        {
          my_array[teller] = 2;
          teller++;
          delay(250);
        }
    }

  lastButtonState_2 = buttonState_2;
}

void loop()
{
  button1();
  button2();
  if (teller == 8)
  {
    teller = 0;
    for (int i = 0; i < 8; i++)
    {
    Serial.println(my_array[i]);
      if (my_array[i] == 1)
      {
        digitalWrite(PIN_LED_GREEN, HIGH);
        delay(500);
        digitalWrite(PIN_LED_GREEN, LOW);
        delay(500);
      }
      if (my_array[i] == 2)
      {
        digitalWrite(PIN_LED_BLUE, HIGH);
        delay(500);
        digitalWrite(PIN_LED_BLUE, LOW);
        delay(500);
      }
    }
  }
}