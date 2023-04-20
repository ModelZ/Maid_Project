#include <Servo.h>

Servo Servo_X; // create a servo object
Servo Servo_Y;

int servoX_Pin = 5; // set the servo pin
int servoY_Pin = 9; // set the servo pin
int angle;

void setup() {
  Serial.begin(9600);
  Servo_X.attach(servoX_Pin); // attach the servo to the specified pin
  Servo_Y.attach(servoY_Pin);
}

void loop() {
  // rotate the servo to 90 degrees
  if (Serial.available() > 0) { // check if there is data available on the serial port
    angle = Serial.parseInt(); // read the incoming byte
  
    Serial.print("Turn ");
    Serial.print(angle);
    Serial.println(" Degrees");
    Servo_X.write(angle);
    Servo_Y.write(angle);
    delay(2000);
  }

  // rotate the servo to 180 degrees
  Serial.println("Turn 180 Degrees");
  Servo_X.write(180);
  Servo_Y.write(180);
  delay(3000);

  // return the servo to 0 degrees
  Serial.println("Turn 0 Degrees");
  Servo_X.write(0);
  Servo_Y.write(0);
  delay(3000);
}
