/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.12.26
resource;



 */

const int laser1 = 11;
const int sensor1 = 10;

const int laser2 = 9;
const int sensor2 = 8;

const int laser3 = 7;
const int sensor3 = 4;

const int ledStrip = 6;
const int speaker = 5;

void setup() {

  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  pinMode(ledStrip, OUTPUT);
  pinMode(speaker, OUTPUT);

  // Turn lasers on
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);
}

void loop() {

  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  int s3 = digitalRead(sensor3);

  // If any beam is broken
  if (s1 == LOW || s2 == LOW || s3 == LOW) {

    digitalWrite(ledStrip, HIGH);

    tone(speaker, 1000); // play sound

  } else {

    digitalWrite(ledStrip, LOW);

    noTone(speaker); // stop sound

// Pin definitions
#include <Adafruit_NeoPixel.h>

const int laserPin = 6;
const int sensorPin = 3;
const int ledPin = 5;
const int speakerPin = 10;

#define STRIP_PIN 11
#define NUM_LEDS 8   // change if your strip has more LEDs

Adafruit_NeoPixel strip(NUM_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pinMode(laserPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  digitalWrite(laserPin, HIGH); // laser on

  strip.begin();
  strip.show(); // start with strip off
}

void loop() {

  int sensorState = digitalRead(sensorPin);

  if (sensorState == LOW) {

    // Turn LED on
    digitalWrite(ledPin, HIGH);

    // LED strip turns red
    for(int i=0; i<NUM_LEDS; i++){
      strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();

    // NEW speaker sound (rising alert tone)
    tone(speakerPin, 1200);
    delay(150);
    tone(speakerPin, 1500);
    delay(150);
    tone(speakerPin, 1800);
    delay(150);
    noTone(speakerPin);

    delay(400);

  } 
  else {

    digitalWrite(ledPin, LOW);

    // LED strip off
    strip.clear();
    strip.show();

    noTone(speakerPin);


  }
}