/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.12.26
resource;



 */
#include <Adafruit_NeoPixel.h>  // Library used to control the NeoPixel LED strip

// -----------------------------
// Laser and sensor pin numbers
// -----------------------------
const int laser1 = 11;   // Laser 1 output pin
const int sensor1 = 10;  // Sensor 1 input pin

const int laser2 = 9;    // Laser 2 output pin
const int sensor2 = 8;   // Sensor 2 input pin

const int laser3 = 7;    // Laser 3 output pin
const int sensor3 = 4;   // Sensor 3 input pin

// -----------------------------
// Other outputs
// -----------------------------
const int speaker = 5;   // Speaker / buzzer pin for alarm sound

// LED strip settings
#define STRIP_PIN 6      // Pin connected to the NeoPixel data line
#define NUM_LEDS 8       // Number of LEDs on the strip

// Create the NeoPixel strip object
Adafruit_NeoPixel strip(NUM_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  // Set laser pins as outputs so they can power the laser modules
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);

  // Set sensor pins as inputs to read the beam sensors
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  // Set the speaker pin as an output
  pinMode(speaker, OUTPUT);

  // Turn all lasers ON so the beams are active
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);

  // Initialize the LED strip
  strip.begin();

  // Turn all LEDs off at startup
  strip.show();
}

void loop() {

  // Read the current state of each laser sensor
  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  int s3 = digitalRead(sensor3);

  // -------------------------------------------------
  // If ANY laser beam is broken, trigger the alarm
  // -------------------------------------------------
  if (s1 == LOW || s2 == LOW || s3 == LOW) {

    // Turn the entire LED strip RED
    for(int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();

    // Play a rising alarm sound through the speaker
    tone(speaker, 1200);   // First tone
    delay(150);

    tone(speaker, 1500);   // Higher tone
    delay(150);

    tone(speaker, 1800);   // Highest tone
    delay(150);

    noTone(speaker);       // Stop the sound

  }
  else {

    // If beams are NOT broken, turn LEDs off
    strip.clear();
    strip.show();

    // Ensure the speaker is silent
    noTone(speaker);
  }
} 