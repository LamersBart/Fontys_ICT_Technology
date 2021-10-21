#include <Arduino.h>

// HW-067 (Kleuren sensor)
// 2x ground, 1x vcc op 5v
const int PIN_RGB_BLUE = 3;
const int PIN_RGB_GREEN = 5;
const int PIN_RGB_RED = 6;
const int OUTPUT_SENSOR = 8;
const int S0 = 12;
const int S1 = 10;
const int S2 = 7;
const int S3 = 9;

String message;
String array[20];
int arrayRood[15];
int arrayGroen[15];
int arrayBlauw[15];
int teller = 0;

int tellerRood = 0;
int tellerGroen = 0;
int tellerBlauw = 0;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int minRood = 0;
int maxRood = 0;
int minGroen = 0;
int maxGroen = 0;
int minBlauw = 0;
int maxBlauw = 0;
const int range = 2;

void KalibreerRood()
{
  //RED filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  //Output freq uitlezen
  arrayRood[tellerRood] = pulseIn(OUTPUT_SENSOR, LOW);

  Serial.print("R = ");
  Serial.print(arrayRood[tellerRood]);
  Serial.print(" ");
  tellerRood++;
}

void KalibreerValuesRood()
{
  for (int i = 0; i < 15; i++)
  {
    KalibreerRood();
    minRood = arrayRood[0];
    maxRood = arrayRood[0];
  }
  for (int i = 0; i < 15; i++)
  {
    if (arrayRood[i] > maxRood)
    {
      maxRood = arrayRood[i];
    }
    if (arrayRood[i] < minRood)
    {
     minRood = arrayRood[i];
    }
  }
  minRood = minRood - range;
  maxRood = maxRood + range;
  Serial.println("");
  Serial.print("Min: ");
  Serial.println(minRood);
  Serial.print("Min: ");
  Serial.println(maxRood);
  Serial.println("");
}

void KalibreerGroen()
{
  //GREEN filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  //Output freq uitlezen
  arrayGroen[tellerGroen] = pulseIn(OUTPUT_SENSOR, LOW);

  Serial.print("G = ");
  Serial.print(arrayGroen[tellerGroen]);
  Serial.print(" ");
  tellerGroen++;
}

void KalibreerValuesGroen()
{
  for (int i = 0; i < 15; i++)
  {
    KalibreerGroen();
    minGroen = arrayGroen[0];
    maxGroen = arrayGroen[0];
  }
  for (int i = 0; i < 15; i++)
  {
    if (arrayGroen[i] > maxGroen)
    {
      maxGroen = arrayGroen[i];
    }
    if (arrayGroen[i] < minGroen)
    {
      minGroen = arrayGroen[i];
    }
  }
  minGroen = minGroen - range;
  maxGroen = maxGroen + range;
  Serial.println("");
  Serial.print("Min: ");
  Serial.println(minGroen);
  Serial.print("Max: ");
  Serial.println(maxGroen);
  Serial.println("");
}

void KalibreerBlauw()
{
  //BLUE filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  //Output freq uitlezen
  arrayBlauw[tellerBlauw] = pulseIn(OUTPUT_SENSOR, LOW);

  Serial.print("B = ");
  Serial.print(arrayBlauw[tellerBlauw]);
  Serial.print(" ");
  tellerBlauw++;
}

void KalibreerValuesBlauw()
{
  for (int i = 0; i < 15; i++)
  {
    KalibreerBlauw();
    minBlauw = arrayBlauw[0];
    maxBlauw = arrayBlauw[0];
  }
  for (int i = 0; i < 15; i++)
  {
    if (arrayBlauw[i] > maxBlauw)
    {
      maxBlauw = arrayBlauw[i];
    }
    if (arrayBlauw[i] < minBlauw)
    {
      minBlauw = arrayBlauw[i];
    }
  }
  minBlauw = minBlauw - range;
  maxBlauw = maxBlauw + range;
  Serial.println("");
  Serial.print("Min: ");
  Serial.println(minBlauw);
  Serial.print("Max: ");
  Serial.println(maxBlauw);
  Serial.println("");
}

void Uitvoeren()
{
  for (int i = 0; i < teller; i++)
  {
    if (array[i] == "Rood")
    {
      Serial.println("Rood");
      digitalWrite(PIN_RGB_RED, HIGH);
      delay(500);
      digitalWrite(PIN_RGB_RED, LOW);
      delay(500);
    }
    if (array[i] == "Groen")
    {
      Serial.println("Groen");
      digitalWrite(PIN_RGB_GREEN, HIGH);
      delay(500);
      digitalWrite(PIN_RGB_GREEN, LOW);
      delay(500);
    }
    if (array[i] == "Blauw")
    {
      Serial.println("Blauw");
      digitalWrite(PIN_RGB_BLUE, HIGH);
      delay(500);
      digitalWrite(PIN_RGB_BLUE, LOW);
      delay(500);
    }
  }
  Serial.println("");
  Serial.println("Uitvoeren voltooid!");
  Serial.println("");
  for (int i = 0; i < 20; i++)
  {
    array[i] = "";
  }
}

void Scannen()
{
  //RED filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  //Output freq uitlezen
  redFrequency = pulseIn(OUTPUT_SENSOR, LOW);
  //GREEN filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //Output freq uitlezen
  greenFrequency = pulseIn(OUTPUT_SENSOR, LOW);
  //BLUE filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //Output freq uitlezen
  blueFrequency = pulseIn(OUTPUT_SENSOR, LOW);
  if (redFrequency > minRood && redFrequency < maxRood)
  {
    array[teller] = "Rood";
    Serial.println("Dit is rood");
    Serial.println("");
    teller++;
  }
  else if (greenFrequency > minGroen && greenFrequency < maxGroen)
  {
    array[teller] = "Groen";
    Serial.println("Dit is Groen");
    Serial.println("");
    teller++;
  }
  else if (blueFrequency > minBlauw && blueFrequency < maxBlauw)
  {
    array[teller] = "Blauw";
    Serial.println("Dit is Blauw");
    Serial.println("");
    teller++;
  }
}

void Printen(int AantalScans)
{
  for (int i = 0; i < AantalScans; i++)
  {
    Serial.print("Scan ");
    Serial.print(i + 1);
    Serial.print(" = ");
    Serial.println(array[i]);
  }
  Serial.println("");
}

void Instructies()
{
  Serial.println("");
  Serial.println("Commando's:");
  Serial.println("Typ: 'Kalibreer R of G of B' voor kleur calibratie.");
  Serial.println("Typ: 'Scan' om te scannen.");
  Serial.println("Typ: 'Print' om scans uit te printen.");
  Serial.println("Typ: 'Uitvoeren' om scans uit te voeren.");
  Serial.println("Typ: 'Instructies' voor beschikbare commando's.");
  Serial.println("");
}

void setup() 
{
  Serial.begin(9600);
  //Pinmodes
  pinMode(PIN_RGB_RED, OUTPUT);
  pinMode(PIN_RGB_GREEN, OUTPUT);
  pinMode(PIN_RGB_BLUE, OUTPUT);
  pinMode(OUTPUT_SENSOR, INPUT);
  pinMode(S0, OUTPUT); 
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  //Freq 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.println("Setup complete!");
  Instructies();
}

void loop() 
{
  if (Serial.available() > 0)
  {
    char received = Serial.read();
    if (received == '\n') // Message is finished, so process message.
    {
      Serial.println("Arduino Received: " + message); // Only for debugging.
      if (message == "Scan")
      {
        Scannen();
      } else if (message == "Print")
      {
        Printen(teller);
      } else if (message == "Uitvoeren")
      {
        Uitvoeren();
        teller = 0;
      } else if (message == "Kalibreer R")
      {
        KalibreerValuesRood();
      } else if (message == "Kalibreer G")
      {
        KalibreerValuesGroen();
      } else if (message == "Kalibreer B")
      {
        KalibreerValuesBlauw();
      } else if (message == "Instructies")
      {
        Instructies();
      } else {
        Serial.println("Foutieve invoer!");
      }
      message = "";      
    }
    else  // Message is not finished yet, so add the received character to message.
    {
      message += received;
    }
  }
}