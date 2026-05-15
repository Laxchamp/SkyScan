/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.12.26
resource;


*/
#include <Adafruit_NeoPixel.h>

// Laser pins
const int laser1 = 11;
const int sensor1 = 10;

const int laser2 = 9;
const int sensor2 = 8;

// Speaker
const int speaker = 5;

// LED strip
#define STRIP_PIN 6
#define NUM_LEDS 8

Adafruit_NeoPixel strip(NUM_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

// Track beam break time
unsigned long breakStart = 0;
bool beamBroken = false;

void setup() {
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  pinMode(speaker, OUTPUT);

  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);

  strip.begin();
  strip.show();
}

void loop() {

  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);

  // If beam is broken
  if (s1 == LOW || s2 == LOW) {

    if (!beamBroken) {
      breakStart = millis();
      beamBroken = true;
    }

    unsigned long elapsed = millis() - breakStart;

    // Beep speed: faster over time
    int beepDelay = 600;
    if (elapsed > 3000) beepDelay = 400;
    if (elapsed > 6000) beepDelay = 250;
    if (elapsed > 9000) beepDelay = 120;

    // LED strip ON (red)
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();

    tone(speaker, 1800);
    delay(beepDelay);

    strip.clear();
    strip.show();
    noTone(speaker);

    delay(beepDelay);

    // If > 12 seconds, trigger bomb explosion effect
    if (elapsed > 12000) {
      bombExplosion();
      beamBroken = false; // reset countdown
    }
  }
  else {
    beamBroken = false;
    strip.clear();
    strip.show();
    noTone(speaker);
  }
}

// -----------------------------
// Bomb explosion effect
// -----------------------------
void bombExplosion() {
  // Rapid strobe
  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255,255,0)); // bright yellow
    }
    strip.show();
    tone(speaker, 2500); // high loud tone
    delay(50);

    strip.clear();
    strip.show();
    noTone(speaker);
    delay(50);
  }
}