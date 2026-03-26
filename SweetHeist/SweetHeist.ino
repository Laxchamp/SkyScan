#include <Adafruit_NeoPixel.h>

// Sensor pins
const int sensor1 = 2;
const int sensor2 = 3;

// LED strip setup
#define LED_PIN 6
#define NUM_LEDS 8  // change to your strip length

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  strip.begin();
  strip.show(); // initialize LEDs off
}

void loop() {
  int beam1 = digitalRead(sensor1);
  int beam2 = digitalRead(sensor2);

  // If either beam is broken
  if (beam1 == LOW || beam2 == LOW) {
    setColor(255, 0, 0); // RED
  } else {
    setColor(0, 0, 0); // OFF
  }

  delay(50);
}

// Function to set all LEDs
void setColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}