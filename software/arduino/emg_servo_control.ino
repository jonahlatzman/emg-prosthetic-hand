#include <Servo.h>

Servo myServo;

int emgPin = A0;
int fsrPin = A1;
int motorPin = 6;
int ledPin = 5;
int threshold = 60;

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;

void setup() {
  myServo.attach(9);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < numReadings; i++) readings[i] = 0;
}

void loop() {
  total -= readings[readIndex];
  readings[readIndex] = analogRead(emgPin);
  total += readings[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  int emgSmoothed = total / numReadings;

  int fsrValue = analogRead(fsrPin);

  Serial.print("EMG: ");
  Serial.print(emgSmoothed);
  Serial.print("  FSR: ");
  Serial.println(fsrValue);

  if (emgSmoothed > threshold) {
    myServo.write(180);
  } else {
    myServo.write(0);
  }

  analogWrite(motorPin, map(fsrValue, 0, 940, 0, 255));
  analogWrite(ledPin, map(fsrValue, 0, 940, 0, 255));

  delay(50);
}
