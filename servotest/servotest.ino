#include <Servo.h>

Servo myservo;

char user_input ;

void setup() {
  Serial.begin(9600);
  myservo.attach(3); // กำหนดขา 5 ของ Servo
}

void loop() {
  /*
  if (Serial.available()>0)
  {
    char select_mode = Serial.read();
    user_input = select_mode;
    if(select_mode != NULL)
      user_input = select_mode;
    else
      user_input = user_input; 
  }
  
  Serial.println(user_input);
  delay(500);
  
  if (user_input == '0') // สั่งให้ Servo หมุนไปที่ 0 องศา
  {
    Serial.println("Servo 0 degree");
    myservo.write(0);
    delay(1000);
  }
  else if (user_input == '1') // สั่งให้ Servo หมุนไปที่ 45 องศา
  {
    Serial.println("Servo 45 degree");
    myservo.write(45);
    delay(1000);
  }
  else if (user_input == '2') // สั่งให้ Servo หมุนไปที่ 90 องศา
  {
    Serial.println("Servo 90 degree");
    myservo.write(90);
    delay(1000);
  }
  else if (user_input == '3') // สั่งให้ Servo หมุนไปที่ 135 องศา
  {
    Serial.println("Servo 135 degree");
    myservo.write(135);
    delay(1000);
  }
  else if (user_input == '4') // สั่งให้ Servo หมุนไปที่ 180 องศา
  {
    Serial.println("Servo 180 degree");
    myservo.write(180);
    delay(1000);
  } 
*/
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
  
}
