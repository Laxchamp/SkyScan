/*
  Blink
By: Cole Rowe
Date: 2.16.26
  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
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
}