#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

#include <stdlib.h>
#include <time.h>

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node //Create node class
{
    public:
        PublisherNode() : Node("node_name"){  //Constructor of Node Class and set node name
            
            // create publisher and set topic
            // this->create_publisher<$msg_type>($topic_name, $QoS);
            publisher_ = this->create_publisher<std_msgs::msg::Float64>(
                "topic_name", 10
            );

            // create calling method timer
            // this->create_wall_timer($duration, $sender_method);
            timer_ = this->create_wall_timer(
                1s, std::bind(&PublisherNode::publish_method, this) 
            );

            std::cout << "pub_node node is running...." << std::endl;

        }

    private:

        // calling method
        void publish_method()
        {
            auto msg = std_msgs::msg::Float64();
            msg.data = rand() % 60; //random rpm 0-60

            //publish message
            publisher_->publish(msg);

        }

        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_; //create publisher object
        rclcpp::TimerBase::SharedPtr timer_; //create timer object

};


int main(int argc, char * argv[]){

    srand(time(0));

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();

    return 0;
}