#include <iostream>
#include <functional>
#include <pigpio.h>

#include "rclcpp/rclcpp.hpp"
#include "mimi_head/msg/movement.hpp"

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
            subscription_ = this->create_subscription<mimi_head::msg::Movement>(
                "head_movement", 10, std::bind(&MimiHeadMovementNode::movement_control, this, std::placeholders::_1)
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
            angle_x = 90;
            angle_z = 90;
            servoX_control();
            servoZ_control();

            // //servo control thread
            // thread servo_ctl(std::bind(&MimiHeadMovementNode::servo_control, this, std::placeholders::_1), mimi_head::msg::Movement());

            // servo_ctl.join();


        }
    
    private:

        void movement_control(const mimi_head::msg::Movement & msg)
        {
            int speed_ms = 10;
            move_x = msg.pos_x; // move left or right direction
            move_z = msg.pos_z; // move up or down direction

            // no face detect
            if(move_x != "unknown" && move_z != "unknown")
            {
                // move left or right
                if(move_x != "ok")
                {
                    if(move_x == "left"){
                        --angle_x;
                        servoX_control();
                    }else if(move_x == "right"){
                        ++angle_x;
                        servoX_control();
                    }
                }
                
                // move up or down
                if(move_z != "ok")
                {
                    if(move_z == "up"){
                        ++angle_z;
                        servoZ_control();
                    }else if(move_z == "down"){
                        --angle_z;
                        servoZ_control();
                    }
                }            
            }

            
        }

        void servoX_control() //subscriptor method with msg recieved
        {

                // Limit of angle_x
                if (angle_x < 0 || angle_x > 180) {

                    RCLCPP_WARN(this->get_logger(),"[angle_X] %d is out of bound", angle_x);  
                    //block out of range
                    if(angle_x < 0) angle_x = 0;
                    if(angle_x > 180) angle_x = 180;

                }

                int pulseWidth_x = 500 + angle_x * 2000 / 180;  // Convert movement to pulse width

                //Error gpioServo() check and turn motor at specific movement
                if (gpioServo(ServoX_Pin, pulseWidth_x) != 0) {
                    RCLCPP_ERROR(this->get_logger(),"Failed to set servo pulse width.");
                    gpioTerminate();
                    exit(3);
                }

                RCLCPP_INFO(this->get_logger(), "[angle_x]: %d", angle_x);

            
        }

        void servoZ_control() //subscriptor method with msg recieved
        {

                // Limit of angle_z

                if (angle_z < 45 || angle_z > 170) {

                    RCLCPP_WARN(this->get_logger(),"[angle_Z] %d is out of bound", angle_z); 
                    //block out of range
                    if(angle_z < 45) angle_z = 45;
                    if(angle_z > 170) angle_z = 170;
                }

                int pulseWidth_z = 500 + angle_z * 2000 / 180;  // Convert movement to pulse width

                //Error gpioServo() check and turn motor at specific movement
                if (gpioServo(ServoZ_Pin, pulseWidth_z) != 0) {
                    RCLCPP_ERROR(this->get_logger(),"Failed to set servo pulse width.");
                    gpioTerminate();
                    exit(3);
                }

                RCLCPP_INFO(this->get_logger(), "[angle_z]: %d", angle_z);
        }

            
        int angle_x, angle_z;
        string move_x, move_z;
        rclcpp::Subscription<mimi_head::msg::Movement>::SharedPtr subscription_;

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