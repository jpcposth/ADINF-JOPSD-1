// Maak variabele aan voor delay
int delayTime = 50;

void setup()
{
  // Stel pin 8 in als een output (LED 1)
  pinMode(8, OUTPUT);
  // Stel pin 10 in als een output (LED 2)
  pinMode(10, OUTPUT);
  // Stel pin 12 in als een input (Button 2)
  pinMode(12, INPUT);
}

void loop() {  
  // Maak een statische variabele aan om de vorige knopstatus bij te houden
  static int previousButtonState = LOW;
  // Maak een statische variabele aan om de teller bij te houden
  static int counter = 0;

  // Lees de huidige status van de knop van pin 12
  int buttonState = digitalRead(12);
  
  // Controleer of er op de knop is gedrukt
  if (buttonState == HIGH && previousButtonState == LOW) {
    // Verhoog de counter met 1
    counter++;
    // Wacht 50 miliseconde
    delay(delayTime);
  }

  // Controleer of de counter een even getal is
  if (counter % 2 == 0) {
  // Zet LED 2 uit
    digitalWrite(10, LOW);
  // Zet LED 1 aan
    digitalWrite(8, HIGH);
  } else {
  // Zet LED 2 uit
    digitalWrite(10, HIGH);
  // Zet LED 1 uit
    digitalWrite(8, LOW);
  }
  
  // Sla de huidige knopstatus op
  previousButtonState = buttonState;
}