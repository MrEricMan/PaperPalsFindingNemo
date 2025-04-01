#include <Servo.h>
Servo myservo; 

// Fortnite battle pass
// setup button A

const int buttonAPin = 2;
int buttonAState = 0;
int lastButtonAState = 0;
bool A = false;

//setup button B
const int buttonBPin = 3;
int buttonBState = 0;
int lastButtonBState = 0;
bool B = false;

void setup() {
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  Serial.begin(9600);
  Serial.println("Start Part A");
}

void loop() {
  buttonAState = digitalRead(buttonAPin);

  // Read Button A
  if (buttonAState != lastButtonAState) {
    if (buttonAState == HIGH) {
      A = true;
      Serial.println("Start Part B");
    }
  }

  // if A is true, read button B
  if (A == true) {
    buttonBState = digitalRead(buttonBPin);
    if (buttonBState != lastButtonBState) {
      if (buttonBState == HIGH) {
      B = true;
      }
    }
  }

  if (B == true) {
    Serial.println("The End!");
  }

  lastButtonAState = buttonAState;
  lastButtonBState = buttonBState;
}
