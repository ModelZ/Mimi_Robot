#include <iostream>
#include <pigpio.h>

// Pin assignment for the servo
const int ServoX_Pin = 18;  // servoX_Pin
const int ServoZ_Pin = 19;  // servoX_Pin

int main() {

    //Error gpioInitialise() check
    if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio library." << std::endl;
        return 1;
    }

    //Error gpioSetMode() check
    if (gpioSetMode(ServoX_Pin, PI_OUTPUT) != 0 || gpioSetMode(ServoZ_Pin, PI_OUTPUT) != 0) {
        std::cerr << "Failed to set servo pin mode." << std::endl;
        gpioTerminate();
        return 1;
    }

    while (true) {

        int angle_x,angle_z;

        std::cout << "Enter the servo angle_X (0-180): ";
        std::cin >> angle_x;
        std::cout << "Enter the servo angle_Z (0-180): ";
        std::cin >> angle_z;

        // Limit of angle_x and angle_z
        if (angle_x < 0 || angle_x > 180) {
            std::cerr << "Invalid angle_x. Enter a value between 0 and 180." << std::endl;   
            //block out of range
            if(angle_x < 0) angle_x = 0;
            if(angle_x > 180) angle_x = 180;

        }

        if (angle_z < 45 || angle_z > 170) {
            std::cerr << "Invalid angle_z. Enter a value between 0 and 180." << std::endl;
            //block out of range
            if(angle_z < 45) angle_z = 45;
            if(angle_z > 170) angle_z = 170;
        }

        int pulseWidth_x = 500 + angle_x * 2000 / 180;  // Convert angle to pulse width
        int pulseWidth_z = 500 + angle_z * 2000 / 180;  // Convert angle to pulse width

        // Error gpioServo() check and turn motor at specific angle
        if (gpioServo(ServoX_Pin, pulseWidth_x) != 0 || gpioServo(ServoZ_Pin, pulseWidth_z)) {
            std::cerr << "Failed to set servo pulse width." << std::endl;
            gpioTerminate();
            return 1;
        }


        // Print out angle_x and angle_y
        std::cout << "Servo angle_x set: " << angle_x << std::endl;
        std::cout << "Servo angle_z set: " << angle_z << std::endl;
    }

    gpioTerminate();
    return 0;
}
