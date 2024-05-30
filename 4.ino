/**
 * @author https://chatgpt.com
 */

// Zet alle LEDs in een array
const int pinArray[] = {3, 5, 7, 9, 11, 13};
      // Variabele om de sensorwaarde op te slaan
      int sensorValue = 0;
      // Maak variabele aan voor delay
      int delayTime = 100;

void setup() {
  // Stel elke pin in de array in als een output
  for (int count = 0; count < 6; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  // Lees de waarde van de analoge sensor
  sensorValue = analogRead(A0);
  
  // Bereken hoeveel LED's dat moet worden ingeschakeld
  // De sensorwaarde wordt omgezet naar 0-6 LED's
  int ledsOn = 6 - map(sensorValue, 0, 1023, 0, 6);

  // Schakel de LED's in of uit afhankelijk van de sensorwaarde
  for (int i = 0; i < 6; i++) {
    if (i < ledsOn) {
      // Zet de LED aan
      digitalWrite(pinArray[i], HIGH);
    } else {
      // Zet de LED uit
      digitalWrite(pinArray[i], LOW);
    }
  }

  // Wacht 0,1 seconde
  delay(delayTime);
}