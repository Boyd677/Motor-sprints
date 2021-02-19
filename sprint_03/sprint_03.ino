//https://www.instructables.com/Controlling-3-servo-motors-with-3-potentiometers-a/
//I used code from instructables for using 3 servos with potentiometers
// I removed the code for the third motor as we only have 2 and made a crane
#include <Servo.h>

Servo myservo3;

Servo myservo5;



int potpin = 0;
int potpin2 = 1;



int val = 0;
int val2 = 0;



void setup()
{

myservo3.attach(3);
myservo5.attach(6);


}

void loop()
{ 

val = analogRead(potpin);
val = map(val, 3, 1023, 0, 176);

myservo3.write(val);

delay(25);

val2 = analogRead(potpin2);
val2 = map(val2, 3, 1023, 0, 176);

myservo5.write(val2);

delay(25);


}
