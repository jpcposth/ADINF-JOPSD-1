/**
 * @author https://chatgpt.com
 */

// Benodigde library
#include <Servo.h>

// Maak servo object aan
Servo myServo;
// Maak variabele aan voor delay
int delayTime = 100;

void setup() {
  // Stel pin 10 in als een input (Button 1)
  pinMode(10, INPUT);
  // Stel pin 6 in als een input (Button 2)
  pinMode(6, INPUT);
  // Stel pin 13 in voor de servomotor
  myServo.attach(13);
}

void loop() {
  // Wacht 0,1 seconde
  delay(delayTime);

  // Lees de huidige status van de knoppen
  int button1State = digitalRead(10);
  int button2State = digitalRead(6);

  // Controleer de status van de knoppen en beweeg de servo
  if (button1State == HIGH && button2State == HIGH) {
    // Als beide knoppen worden ingedrukt
    // Beweeg de servo van 0 naar 120 graden in 5 seconden
    moveServo(0, 120, 5000);
    // Wacht 2 seconde
    delay(2000);
    // Beweeg de servo van 120 naar 0 graden in 0,5 seconden
    moveServo(120, 0, 500);
  } else if (button1State == HIGH) {
    // Als knop 1 wordt ingedrukt
    // Beweeg de servo van 0 naar 120 graden in 5 seconden
    moveServo(0, 120, 5000);
    // Beweeg de servo van 120 naar 0 graden in 5 seconden
    moveServo(120, 0, 5000);
  } else if (button2State == HIGH) {
    // Als knop 2 wordt ingedrukt
    // Beweeg de servo van 0 naar 120 graden in 0,5 seconden
    moveServo(0, 120, 500);
    // Beweeg de servo van 120 naar 0 graden in 0,5 seconden
    moveServo(120, 0, 500);
  }
}

void moveServo(int startAngle, int endAngle, int duration) {
  // Bereken het totale aantal stappen
  int totalSteps = abs(endAngle - startAngle);
   // Bereken de delay per stap
  int stepDelay = duration / totalSteps;

  // Beweeg de servo van startAngle naar endAngle
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      // Zet de servo naar de huidige hoek
      myServo.write(angle);
      // Wacht de berekende delay
      delay(stepDelay);
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      // Zet de servo naar de huidige hoek
      myServo.write(angle);
      // Wacht de berekende delay
      delay(stepDelay);
    }
  }
}