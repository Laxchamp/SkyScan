/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.12.26
resource;



 */
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