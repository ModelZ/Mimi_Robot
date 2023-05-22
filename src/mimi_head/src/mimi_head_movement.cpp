#include <iostream>
#include <functional>
#include <pigpio.h>

#include "rclcpp/rclcpp.hpp"
#include "mimi_head/msg/angle.hpp"

using namespace std;

// Pin assignment for the servo
const int ServoX_Pin = 18;  // servoX_Pin
const int ServoZ_Pin = 19;  // servoX_Pin

class MimiHeadMovementNode : public rclcpp::Node // Create node class
{
    public:
        MimiHeadMovementNode() : Node("mimi_head_movement_node") //Constructor of Node Class and set node name
        {
            // create subscription
            // this->create_subscription<$msg_type>($topic_name, $QoS, $servo_control);
            subscription_ = this->create_subscription<mimi_head::msg::Angle>(
                "head_movement_angle", 10, std::bind(&MimiHeadMovementNode::servo_control, this, std::placeholders::_1)
            );

             //Error gpioInitialise() check
            if (gpioInitialise() < 0) {
                RCLCPP_ERROR(this->get_logger(),"Failed to initialize pigpio library.");
                exit(1);
            }

            //Error gpioSetMode() check
            if (gpioSetMode(ServoX_Pin, PI_OUTPUT) != 0 || gpioSetMode(ServoZ_Pin, PI_OUTPUT) != 0) {
                RCLCPP_ERROR(this->get_logger(),"Failed to set servo pin mode.");
                gpioTerminate();
                exit(2);
            }

            // initialize face
            mimi_head::msg::Angle init_angle;
            init_angle.angle_x = 90;
            init_angle.angle_z = 90;

            servo_control(init_angle);

            // //servo control thread
            // thread servo_ctl(std::bind(&MimiHeadMovementNode::servo_control, this, std::placeholders::_1), mimi_head::msg::Angle());

            // servo_ctl.join();


        }
    
    private:

        void servo_control(const mimi_head::msg::Angle & msg) //subscriptor method with msg recieved
        {
            // while (true)
            // {
                angle_x = msg.angle_x;
                angle_z = msg.angle_z;


                // Limit of angle_x and angle_z
                if (angle_x < 0 || angle_x > 180) {

                    RCLCPP_WARN(this->get_logger(),"[angle_X] %d is out of bound", angle_x);  
                    //block out of range
                    if(angle_x < 0) angle_x = 0;
                    if(angle_x > 180) angle_x = 180;

                }

                if (angle_z < 45 || angle_z > 170) {

                    RCLCPP_WARN(this->get_logger(),"[angle_Z] %d is out of bound", angle_z); 
                    //block out of range
                    if(angle_z < 45) angle_z = 45;
                    if(angle_z > 170) angle_z = 170;
                }

                int pulseWidth_x = 500 + angle_x * 2000 / 180;  // Convert angle to pulse width
                int pulseWidth_z = 500 + angle_z * 2000 / 180;  // Convert angle to pulse width

                //Error gpioServo() check and turn motor at specific angle
                if (gpioServo(ServoX_Pin, pulseWidth_x) != 0 || gpioServo(ServoZ_Pin, pulseWidth_z)) {
                    RCLCPP_ERROR(this->get_logger(),"Failed to set servo pulse width.");
                    gpioTerminate();
                    exit(3);
                }

                RCLCPP_INFO(this->get_logger(), "[angle_x]: %d [angle_z]: %d", angle_x, angle_z);


            // }

            // gpioTerminate();
            
        }
        
        int angle_x, angle_z;
        rclcpp::Subscription<mimi_head::msg::Angle>::SharedPtr subscription_;

}; 

void sigint_handler(int sig)
{
    rclcpp::shutdown();
    gpioTerminate();
    exit(0);
}

int main(int argc, char * argv[]){

    // Set up signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MimiHeadMovementNode>());
    rclcpp::shutdown();
    gpioTerminate();

    return 0;
    
}