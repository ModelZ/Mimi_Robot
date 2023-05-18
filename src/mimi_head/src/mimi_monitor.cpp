#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

using namespace std;
using namespace cv;


class MimiMonitorNode : public rclcpp::Node // Create node class
{
    public:
        MimiMonitorNode() : Node("mimi_monitor_node") //Constructor of Node Class and set node name
        {
            // create subscription
            // this->create_subscription<$msg_type>($topic_name, $QoS, $mimi_monitor);
            subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
                "mimi_vision_monitor", 10, std::bind(&MimiMonitorNode::mimi_monitor, this, std::placeholders::_1)
            );

            // print out
            std::cout << "mimi_monitor_node node is running...." << std::endl;

        }
    
    private:

        void mimi_monitor(const sensor_msgs::msg::Image & img) //subscriptor method with msg recieved
        {

            auto cv_ptr = cv_bridge::toCvCopy(img, "bgr8"); // convert ROS2 image to OpenCV Matrix

            Mat image = cv_ptr->image; //get converted Mat image
        
            imshow("Mimi Vision", image); //show response image

            waitKey(20);

        }

        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;

}; 

void sigint_handler(int sig)
{
    destroyAllWindows();
    rclcpp::shutdown();
    exit(0);
}

int main(int argc, char * argv[]){

    // Set up signal handler for SIGINT
    signal(SIGINT, sigint_handler);
    
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MimiMonitorNode>());
    rclcpp::shutdown();

    return 0;
}