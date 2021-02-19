/*
 *unfortunately I used just button servo tutorial code for this with very little modification
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 */

#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 3; 
const int SERVO_PIN  = 6; // Arduino pin connected to servo motor's pin

Servo servo; 

// variables will change:
int angle = 0;          
int lastButtonState;    
int currentButtonState; 

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  servo.attach(SERVO_PIN);           
  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      
  currentButtonState = digitalRead(BUTTON_PIN); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    
    if(angle == 0)
      angle = 90;
    else
    if(angle == 90)
      angle = 0;

    
    servo.write(angle);
  }
}
