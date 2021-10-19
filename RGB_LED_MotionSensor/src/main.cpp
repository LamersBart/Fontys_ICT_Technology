#include <Arduino.h>

// const int variabele aangemaakt om waarde door heel de code hetzelfde te houden
const int rood_licht_pin = 11;
const int groen_licht_pin = 10;
const int blauw_licht_pin = 9;
const int pirPin = 2;   // PIR Out pin 
const int arrayKleur[3] = {0, 150, 255};

//standaard code opgeleverd opdracht14
String message; 

// hier maak je variabele aan om de status, de teller en de brandende lampjes een waarde te geven
int pirStat = 0; 
int pirCount = 0;
int delayKnipper = 1000;

void RGB_Kleur(int rood_licht_value, int groen_licht_value, int blauw_licht_value)  
{
  // Dit schrijft de analoge waarde uit voor de kleur pins
  analogWrite(rood_licht_pin, rood_licht_value);
  analogWrite(groen_licht_pin, groen_licht_value);
  analogWrite(blauw_licht_pin, blauw_licht_value);
}

void setup()  
{
  pinMode(rood_licht_pin, OUTPUT);
  pinMode(groen_licht_pin, OUTPUT);
  pinMode(blauw_licht_pin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // hiermee lees je de status uit van pirpin en geef je die aan pirstat
  pirStat = digitalRead(pirPin);
  if (pirStat == LOW)
  {
    // toegevoegd om de kleuren uit te zetten
    RGB_Kleur(0, 0, 0);
  }
  //standaard code opgeleverd opdracht14
  if (Serial.available() > 0)
  {
    char received = Serial.read();
    if (received == '\n')
    {
      Serial.println("Arduino Received: " + message);
      // met de invoer van 'start' begint de detectie
      if (message == "Start")
      {
        // hiermee lees je weer de status uit
        pirStat = digitalRead(pirPin);
        // is de status LOW dan voert ie de while loop uit    
        while (pirStat == LOW)
        {
          // nu zit je in de while loop, hier lees je weer opnieuw de status uit
          pirStat = digitalRead(pirPin);
          // zolang de status low blijft wrdt het volgende stukje tekst geprint : "Niks te zien..."
          Serial.println("Niks te zien...");
          // als de motion sensor iets gesignaleerd heeft dan voert hij het volgende uit:
          if (pirStat == HIGH) 
          {         
            // De RODE LED gaat nu aan
            RGB_Kleur(255, 0, 0);
            pirCount++;
            delay(100);
            Serial.println("Je bent gedecteert");
            Serial.print("Aantal keer: ");
            Serial.println(pirCount);
          }
        }
        // met de invoer "Uitkomst" en de detectie die de sensor 3x doet, voert ie het volgende uit
      } else if (pirCount == 3 && message == "Uitkomst")
      {
        // Waarde van pircount wordt gereset waardoor er straks weer tot 3 kan worden opgeteld
        pirCount = 0;
        // hiermee zet je de lamp aan (blauw/groenig)
        RGB_Kleur(arrayKleur[0], arrayKleur[1], arrayKleur[2]);
        delay(delayKnipper);
        // de delay voeg je toe om te voorkomen dat het lampje gelijk van kleur veranderd
        RGB_Kleur(0, 0, 0);
        delay(delayKnipper);
        // hiermee zet je de lamp aan (paarsig, je zet blauw en rood open)
        RGB_Kleur(arrayKleur[2], arrayKleur[0], arrayKleur[1]);
        delay(delayKnipper);
        RGB_Kleur(0, 0, 0);
        delay(delayKnipper);
        // hiermee zet je de lamp aan (groenMAX, rood beetje)
        RGB_Kleur(arrayKleur[1], arrayKleur[2], arrayKleur[0]);
        delay(delayKnipper);
      }
      message = ""; // Message is processed, so clear message.
    }
    else  // Message is not finished yet, so add the received character to message.
    {
      message += received;
    }
  }
}