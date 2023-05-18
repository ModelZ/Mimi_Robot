#include <Servo.h>

Servo Servo_X; // create a servo object
Servo Servo_Z;

int servoX_Pin = 3; // set the servo pin
int servoY_Pin = 5; // set the servo pin
float angle_X, angle_Z;
String str_angle;

void setup() {
  Serial.begin(115200);

  // attach the servo to the specified pin
  Servo_X.attach(servoX_Pin); 
  Servo_Z.attach(servoY_Pin);
  
  // straight face
  Servo_X.write(90);
  Servo_Z.write(90); 
}

void loop() {
  // rotate the servo to 90 degrees
  if (Serial.available()) { // check if there is data available on the serial port

    //Read data from UART serial port from raspberryPi 
    str_angle = Serial.readStringUntil('\n'); //[ServoX] [ServoY]

    //Cut string into 2 float numbers to control 2 servo motors
    angle_X = str_angle.substring(0, str_angle.indexOf(" ") == -1 ? str_angle.length() : str_angle.indexOf(" ")).toFloat(); //[ServoX] value
    angle_Z = str_angle.substring(str_angle.indexOf(" ") + 1, str_angle.length()).toFloat(); //[ServoZ] value


    //debug 1

    // Serial.print(angle_X);
    // Serial.print(" ");
    // Serial.println(angle_Z);

    //Block out of bound exception
    if(angle_X > 180 || angle_X < 0){

            
      Serial.print("Warning: [angle_X] ");
      Serial.print(angle_X);
      Serial.println(" is Out of bound");

      if(angle_X > 180)
        angle_X = 180;
      if(angle_X < 0)
        angle_X < 0;

    }
      
    if(angle_Z > 180 || angle_Z < 0){

      Serial.print("Warning: [angle_Z] ");
      Serial.print(angle_Z);
      Serial.println(" is Out of bound");

      if(angle_Z > 180)
        angle_Z = 180;
      if(angle_Z < 0)
        angle_Z < 0;
      
    }


    //debug 2

    // Serial.print(angle_X);
    // Serial.print(" ");
    // Serial.println(angle_Z);
    
    //Turn servos
    Servo_X.write(angle_X);
    Servo_Z.write(angle_Z);    
  

  }
 
}
