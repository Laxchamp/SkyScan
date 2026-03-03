/*
Developers: Cole Rowe, Ty Robicheaux
Date: 2.24.26 
resource;

 */
int laserPin = 10; 
int sensorPin = 6; 
int ledPin = 11; 
 
void setup() { 
  pinMode(laserPin, OUTPUT); 
  pinMode(sensorPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
 
  digitalWrite(laserPin, HIGH); // turn laser ON 
} 
 
void loop() { 
  int sensorState = digitalRead(sensorPin); 
 
  if (sensorState == LOW) { 
    // Laser beam broken → flicker LED 
    digitalWrite(ledPin, HIGH); 
    delay(200); 
    digitalWrite(ledPin, LOW); 
    delay(200); 
  } else { 
    // Laser intact → LED off 
    digitalWrite(ledPin, LOW); 
  }
 
const int laserPin = 6;       // Laser emitter
const int sensorPin = 3;      // Laser receiver
const int ledPin = 5;         // LED indicator

void setup() {
  pinMode(laserPin, OUTPUT);    // Laser as output
  pinMode(sensorPin, INPUT);    // Sensor as input
  pinMode(ledPin, OUTPUT);      // LED as output
  
  digitalWrite(laserPin, HIGH); // Turn laser on
}

void loop() {
  int sensorState = digitalRead(sensorPin); // Read receiver

  if (sensorState == LOW) {
    // Laser is broken (beam interrupted)
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    // Laser is hitting the receiver
    digitalWrite(ledPin, LOW);  // LED off
  }
}