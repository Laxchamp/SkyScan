/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.12.26
resource;



 */
#include <Adafruit_NeoPixel.h>

// Laser and sensor pins
const int laser1 = 11;
const int sensor1 = 10;

const int laser2 = 9;
const int sensor2 = 8;

const int laser3 = 7;
const int sensor3 = 4;

// Outputs
const int speaker = 5;

#define STRIP_PIN 6
#define NUM_LEDS 8

Adafruit_NeoPixel strip(NUM_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  pinMode(speaker, OUTPUT);

  // Turn lasers on
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);

  strip.begin();
  strip.show(); // LEDs off
}

void loop() {

  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  int s3 = digitalRead(sensor3);

  // If any beam is broken
  if (s1 == LOW || s2 == LOW || s3 == LOW) {

    // LED strip red
    for(int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();

    // Rising alert sound
    tone(speaker, 1200);
    delay(150);
    tone(speaker, 1500);
    delay(150);
    tone(speaker, 1800);
    delay(150);
    noTone(speaker);

  }
  else {

    // Turn LEDs off
    strip.clear();
    strip.show();

    noTone(speaker);
  }
}