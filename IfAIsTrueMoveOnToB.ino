#include <Servo.h>

Servo myservoBlood; 
Servo myservoDoor2;
Servo myservoDropper;
Servo myservoTorpedo;

const int buttonPin = 2;
const int buttonPinRoom2 = 3;
const int buttonPinMarlinR2 = 4;
const int buttonPinDoryR2 = 5;

int buttonPinVal;
int buttonPinValRoom2;
int buttonPinValMarlinR2;
int buttonPinValDoryR2;




void setup() {
  Serial.begin(9600);
  myservoBlood.attach(9);
  myservoDoor2.attach(6);
  myservoDropper.attach(10);
  myservoTorpedo.attach(11);
  pinMode(buttonPin, INPUT);
  myservoBlood.write(0);
  myservoDoor2.write(0);
  myservoDropper.write(0);
  myservoTorpedo.write(90);
}




void loop() {
  // The blood drop opens the first door
  buttonPinVal = digitalRead(buttonPin);
  Serial.println(" ");
  Serial.println("Blood");
  Serial.println(buttonPinVal);
  Serial.println(" ");

  if (buttonPinVal == 1) {
      myservoBlood.write(90);

//-------------------------------------------------
// code for oppening the second door
  buttonPinValRoom2 = digitalRead(buttonPinRoom2);
  buttonPinValDoryR2 = digitalRead(buttonPinDoryR2);

  Serial.println("Room2");
  Serial.println(buttonPinValRoom2);
  Serial.println(buttonPinValMarlinR2);
  Serial.println(buttonPinValDoryR2);

  if (buttonPinValDoryR2 == 1){  // Dory and Marlin close the door they came from
    myservoBlood.write(0);
    if (buttonPinValRoom2 == 1) { // they open the new door
    myservoDropper.write(90);
    }
  }
//-------------------------------------------------
// code for revealing bruce the shark at the end
  buttonPinValMarlinR2 = digitalRead(buttonPinMarlinR2);

  if (buttonPinValMarlinR2 == 1){  // Dory and Marlin close the door they came from
    myservoTorpedo.write(0); // servo flips Bruce
    delay(7000);
    myservoTorpedo.write(90);
  }



}
