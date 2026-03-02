/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.2.26
resource;



 */
// Pin definitions
const int laserPin = 6;       // Laser emitter
const int sensorPin = 3;      // Laser receiver
const int ledPin = 5;         // LED indicator
const int speakerPin = 10;    // Speaker

void setup() {
  pinMode(laserPin, OUTPUT);    // Laser as output
  pinMode(sensorPin, INPUT);    // Sensor as input
  pinMode(ledPin, OUTPUT);      // LED as output
  pinMode(speakerPin, OUTPUT);  // Speaker as output

  digitalWrite(laserPin, HIGH); // Turn laser on
}

void loop() {
  int sensorState = digitalRead(sensorPin); // Read receiver

  if (sensorState == LOW) {
    // Laser is broken, blink LED
    digitalWrite(ledPin, HIGH);
    // Play ding sound
    tone(speakerPin, 1000, 150); // 1000 Hz for 150 ms
    delay(200);
    tone(speakerPin, 1000, 150); // second ding
    delay(200);
    tone(speakerPin, 1000, 150); // third ding
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(500); // pause before next blink
  } else {
    // Laser is hitting the receiver
    digitalWrite(ledPin, LOW);  // LED off
    noTone(speakerPin);         // Stop speaker
  }
}