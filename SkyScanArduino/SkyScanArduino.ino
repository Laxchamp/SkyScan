/*
Developers: Cole Rowe, Ty Robicheaux
Date: 3.2.26
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
  }
}