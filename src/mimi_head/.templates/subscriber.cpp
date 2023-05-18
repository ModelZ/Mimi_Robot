#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std;


class SubscriptorNode : public rclcpp::Node // Create node class
{
    public:
        SubscriptorNode() : Node("node_name") //Constructor of Node Class and set node name
        {
            // create subscription
            // this->create_subscription<$msg_type>($topic_name, $QoS, $subscriptor_method);
            subscription_ = this->create_subscription<std_msgs::msg::Float64>(
                "topic_name", 10, std::bind(&SubscriptorNode::subscriptor_method, this, std::placeholders::_1)
            );

        }
    
    private:

        void subscriptor_method(const std_msgs::msg::Float64 & msg) //subscriptor method with msg recieved
        {

            // ** Do anything with msg

        }

        rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;

}; 

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubscriptorNode>());
    rclcpp::shutdown();

    return 0;
}