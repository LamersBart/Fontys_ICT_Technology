#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 1 (KEY1) pin.
int buttonState_1 = 0;  // Keep track of the button 1 state.
int buttonState_2 = 0;  // Keep track of the button 1 state.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int my_array[5];  //Array met 5 integers
  my_array[0] = 23;    // assign a value of 23 to the 1st element
  my_array[1] = 1001;  // assign a value of 1001 to the 2nd element, etc.
  my_array[2] = 9;
  my_array[3] = 1234;
  my_array[4] = 987;
  // display each number from the array in the serial monitor window
  int som = 0;
  for (int i = 0; i < 5; i++) {
    som = som + my_array[i];
    Serial.print(my_array[i]);
    if (i <= 3)
    {
      Serial.print(" + ");
    }
    if (i == 4)
    {
      Serial.print(" = ");
    }
  }
  Serial.println(som);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}