#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std;


class MimiHeadMovementNode : public rclcpp::Node // Create node class
{
    public:
        MimiHeadMovementNode() : Node("mimi_head_movement_node") //Constructor of Node Class and set node name
        {
            // create subscription
            // this->create_subscription<$msg_type>($topic_name, $QoS, $subscriptor_method);
            subscription_ = this->create_subscription<std_msgs::msg::String>(
                "head_movement_angle", 10, std::bind(&MimiHeadMovementNode::subscriptor_method, this, std::placeholders::_1)
            );

        }
    
    private:

        void subscriptor_method(const std_msgs::msg::String & msg) //subscriptor method with msg recieved
        {

            // ** Do anything with msg

        }

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

}; 

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MimiHeadMovementNode>());
    rclcpp::shutdown();

    return 0;
}