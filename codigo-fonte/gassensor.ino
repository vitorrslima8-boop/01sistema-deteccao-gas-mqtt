#include <Servo.h>
// MQ2 Gas Sensor module

Servo ventServo;

const int gasSensorPin = A0;
const int servoPin = 9;
const int buzzerPin = 8;
const int ledPin = 7;

int gasValue = 0;
int threshold = 400;   // Adjust after testing

void setup() {
  Serial.begin(9600);
  
  ventServo.attach(servoPin);
  ventServo.write(0);  // Vent closed initially
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    ventServo.write(90);          // Open vent
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    ventServo.write(0);           // Close vent
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
