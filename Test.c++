int laserSensor = A0;
int ledPin = 9;

int threshold = 500;  // adjust after testing

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(laserSensor);
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    // Laser beam broken
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}