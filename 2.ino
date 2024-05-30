// Zet alle LEDs in een array
const int pinArray[] = {1, 3, 5, 7,8, 9, 11, 13};
      // Maak variabele aan voor delay
      int delayTime = 50;

void setup() {
  // Stel elke pin in de array in als een output
  for (int count = 0; count < 8; count ++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  // Zet alle pinnen in de array één voor één aan
  for (int count = 0; count < 8; count++) {
    digitalWrite(pinArray[count], HIGH);
    // Wacht 50 miliseconde
    delay(delayTime);
  }

  // Zet alle pinnen in de array één voor één uit
  for (int count = 0; count < 8; count++) {
    digitalWrite(pinArray[count], LOW);
    // Wacht 50 miliseconde
    delay(delayTime);
  }


  // Zet alle pinnen in de array in omgekeerde volgorde aan
  for (int count = 7; count >= 0; count--) {
    digitalWrite(pinArray[count], HIGH);
    // Wacht 50 miliseconde
    delay(delayTime);
  }

  // Zet alle pinnen in de array in omgekeerde volgorde uit
  for (int count = 7; count >= 0; count--) {
    digitalWrite(pinArray[count], LOW);
    // Wacht 50 miliseconde
    delay(delayTime); 
  }
}