/**
 * @author https://chatgpt.com
 */

// Benodigde libraries
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Maak variabelen aan voor delay
int delayTime = 100;
int delayReset = 1000;

// Initialiseer het LCD-scherm
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Maak variabelen aan voor tijd bijhouden
unsigned long startTime = 0;
unsigned long pausedTime = 0;
unsigned long button1PressTime = 0;

// Booleans om de status bij te houden
bool running = false;
bool button1Held = false;

void setup() {
  // Stel pin 10 in als een input (Button 1)
  pinMode(10, INPUT);
  // Stel pin 6 in als een input (Button 2)
  pinMode(6, INPUT);

  // Initialiseer het LCD-scherm
  lcd.init();
  lcd.backlight();

  // Start de timer
  startTime = millis();
  displayTime();
}

void loop() {
  // Lees de huidige status van de knoppen
  bool button1State = digitalRead(10);
  bool button2State = digitalRead(6);

  // Als knop 1 wordt ingedrukt
  if (button1State == HIGH) {
    if (!button1Held) {
      // Houd de tijd bij wanneer de knop voor het eerst wordt ingedrukt
      button1PressTime = millis();
      button1Held = true;
    } else if (millis() - button1PressTime >= 2000) {
      // Als knop 1 langer dan 2 seconden wordt ingedrukt
      if (running) {
        // Toon de lap tijd
        displayLap();
      }
      button1Held = false;
      // Wacht 0,1 seconde
      delay(delayTime);
    }
  } else {
    if (button1Held && millis() - button1PressTime < 2000) {
      // Als knop 1 minder dan 2 seconden wordt ingedrukt
      if (!running) {
        if (pausedTime == 0) {
          // Start de timer opnieuw
          startTime = millis();
        } else {
          // Hervat de timer
          startTime += millis() - pausedTime;
          pausedTime = 0;
        }
        running = true;
      // Wacht 0,1 seconde
        delay(delayTime);
      }
    }
    button1Held = false;
  }

  // Als knop 2 wordt ingedrukt
  if (button2State == HIGH) {
    if (running) {
      // Pauzeer de timer
      pausedTime = millis();
      running = false;
    }
  }

  // Wacht 0,1 seconde
  delay(delayTime);

  // Als beide knoppen worden ingedrukt
  if (button1State && button2State) {
    lcd.clear();
    // Reset de timer
    startTime = millis();
    displayTime();
    pausedTime = 0;
    delay(delayReset);
  }

  // Werk de tijd bij als de timer loopt
  if (running) {
    displayTime();
  }
}

void displayTime() {
  // Bereken de tijd
  unsigned long timeElapsed = millis() - startTime;
  unsigned long milliseconds = timeElapsed % 1000;
  unsigned long seconds = timeElapsed / 1000;
  unsigned long minutes = seconds / 60;

  // Bereken minuten en seconden
  seconds %= 60;
  minutes %= 60;

  // Toon de tijd op het LCD-scherm
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.print(minutes < 10 ? "0" : "");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds < 10 ? "0" : "");
  lcd.print(seconds);
  lcd.print(".");
  lcd.print(milliseconds < 100 ? "0" : "");
  lcd.print(milliseconds < 10 ? "0" : "");
  lcd.print(milliseconds);
}

void displayLap() {
  // Bereken de lap tijd
  unsigned long currentTime = millis() - startTime - 2000;
  unsigned long milliseconds = currentTime % 1000;
  unsigned long seconds = currentTime / 1000;
  unsigned long minutes = seconds / 60;

  // Bereken minuten en seconden
  seconds %= 60;
  minutes %= 60;

  // Toon de tijd op het LCD-scherm
  lcd.setCursor(0, 1);
  lcd.print("Lap:");
  lcd.print(minutes < 10 ? "0" : "");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds < 10 ? "0" : "");
  lcd.print(seconds);
  lcd.print(".");
  lcd.print(milliseconds < 100 ? "0" : "");
  lcd.print(milliseconds < 10 ? "0" : "");
  lcd.print(milliseconds);
}