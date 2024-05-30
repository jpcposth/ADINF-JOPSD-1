  // Maak variabele aan voor delay
  int delayTime = 1500;

void setup() {
  // Stel pin 13 in als een output (LED 1)
  pinMode(13, OUTPUT);
  // Stel pin 10 in als een output (LED 2)
  pinMode(10, OUTPUT);
}

void loop() {
  // Zet LED 1 aan
  digitalWrite(13, HIGH);
  // Wacht 1,5 seconde
  delay(delayTime);
  // Zet LED 1 uit
  digitalWrite(13, LOW);
  // Zet LED 2 aan
  digitalWrite(10, HIGH);
  // Wacht 1,5 seconde
  delay(delayTime);
  // Zet LED 2 uit
  digitalWrite(10, LOW);  
}