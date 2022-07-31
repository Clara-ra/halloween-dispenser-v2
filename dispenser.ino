#include <Wire.h> 

const int directionPin = 2; //pin sets the direction the motor is spinning
const int stepPin = 3;  //pin makes the motor take a step
const int detectHandPin = 5; //sensor to detect hand approaching
const int detectCandyPin = 6 //sensor to detect that candy has fallen
const int eyes = 7; //pin LEDs for the eyes
const int audio = 8; //pin for the Audio sound
const int enable = 10;

int reverseBack = 0; //used to keep track of how much more to reverse back after candy has fallen

void setup()
{
  Serial.begin(115200);
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(detectHandPin, INPUT);
  pinMode(detectCandyPin, INPUT);
  pinMode(enable, OUTPUT);
  pinMode(eyes, OUTPUT);
  pinMode(audio, OUTPUT);
  digitalWrite(enable, HIGH);
  digitalWrite(eyes, LOW);
  digitalWrite(audio, HIGH);
}

void loop()
{
  if (handDetected()) {
    Serial.print("Hand detected. Distance: ");
    Serial.println(digitalRead(detectHandPin));

    digitalWrite(directionPin, LOW); //make sure motor is going in the forward direction
    digitalWrite(enable, LOW);

    digitalWrite(eyes, HIGH);
    playAudio();

    while (!candyDetected()) {
      spinMotor();
      Serial.println("Spinning Lazy Susan");
    }
    
    delay(500);

    digitalWrite(directionPin, HIGH); //Now motor needs to go in reverse
    reverseBack = 250;
    
    while (reverseBack > 0) {
      spinMotor();
      Serial.println("Spinning backwards");
      reverseBack--;
    }

    digitalWrite(enable, HIGH);
    digitalWrite(eyes, LOW);
    delay(1000);
  }
  
}

void spinMotor() {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(3000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(3000);
}

void playAudio() {
    digitalWrite(audio, LOW);
    delay(1000);
    digitalWrite(audio, HIGH);
    delay(500);
    // delay(4000);
}

bool handDetected() {
    return digitalRead(detectHandPin) >= 1;
}

bool candyDetected() {
    return digitalRead(detectCandyPin) >= 1;
}
