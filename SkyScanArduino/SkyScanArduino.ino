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