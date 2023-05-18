#include <Servo.h>

Servo Servo_X; // create a servo object
Servo Servo_Z;

int servoX_Pin = 13; // set the servo pin
int servoZ_Pin = 14; // set the servo pin
float angle_X, angle_Z;
String str_angle;

void setup() {
  Serial.begin(115200);

  // attach the servo to the specified pin
  Servo_X.attach(servoX_Pin); 
  Servo_Z.attach(servoZ_Pin);
  
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
    if(angle_X > 180 || angle_X < 0){ //range 0-180 degrees [left 0-89] [Right 91-180] [Mid 90]

            
      Serial.print("Warning: [angle_X] ");
      Serial.print(angle_X);
      Serial.println(" is Out of bound");

      if(angle_X > 180)
        angle_X = 180;
      if(angle_X < 0)
        angle_X = 0;

    }
      
    if(angle_Z > 170 || angle_Z < 45){ //range 45-170 degrees [Up 91-170] [Down 45-89] [Mid 90]

      Serial.print("Warning: [angle_Z] ");
      Serial.print(angle_Z);
      Serial.println(" is Out of bound");

      if(angle_Z > 170)
        angle_Z = 170;
      if(angle_Z < 45)
        angle_Z = 45;
      
    }


    debug 2

    Serial.print(angle_X);
    Serial.print(" ");
    Serial.println(angle_Z);
    
    //Turn servos
    Servo_X.write(angle_X);
    Servo_Z.write(angle_Z);    
  

  }
 
}





// #include <Servo.h>

// static const int servoPin = 13;

// Servo servo1;

// void setup() {
//     Serial.begin(115200);
//     servo1.attach(servoPin);
// }

// void loop() {
  
//     delay(1000);
//     servo1.write(0);
//     Serial.println(0);
//     delay(1000);
//     servo1.write(90);
//     Serial.println(90);
//     delay(1000);
//     servo1.write(180);
//     Serial.println(180);
//     for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
//         servo1.write(posDegrees);
//         Serial.println(posDegrees);
//         delay(20);
//     }

//     for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
//         servo1.write(posDegrees);
//         Serial.println(posDegrees);
//         delay(20);
//     }
// }