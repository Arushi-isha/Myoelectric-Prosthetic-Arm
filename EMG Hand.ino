#include <Servo.h>

Servo Thumb, Index, Middle, Ring, Little;

// Servo pin connections
int thumbPin = 3;
int indexPin = 5;
int middlePin = 6;
int ringPin = 9;
int littlePin = 10;

// EMG sensor input pin
int emgPin = A3;

// Servo position limits
int openPos = 45;
int closePos = 150;

// Calibration thresholds (adjust by checking Serial output)
int threshold = 115;   // signal above this means "muscle flexed"
int restValue = 80;   // relaxed signal level

// Movement speed
int moveDelay = 10;    

void setup() {
  Serial.begin(9600);

  // Attach servos
  Thumb.attach(thumbPin);
  Index.attach(indexPin);
  Middle.attach(middlePin);
  Ring.attach(ringPin);
  Little.attach(littlePin);

  // Start with hand open
  openHand();
}

void loop() {
  int emgValue = analogRead(emgPin);
  Serial.println(emgValue);   // Use Serial Monitor to view values for calibration

  if (emgValue > threshold) {
    closeHand();
  } else if (emgValue < restValue + 20) {
    openHand();
  }

  delay(50);
}

// === Helper Functions ===

void closeHand() {
  for (int pos = openPos; pos <= closePos; pos++) {
    Thumb.write(pos);
    Index.write(pos);
    Middle.write(pos);
    Ring.write(pos);
    Little.write(pos);
    delay(moveDelay);
  }
}

void openHand() {
  for (int pos = closePos; pos >= openPos; pos--) {
    Thumb.write(pos);
    Index.write(pos);
    Middle.write(pos);
    Ring.write(pos);
    Little.write(pos);
    delay(moveDelay);
  }
}
