#include "rclcpp/rclcpp.hpp"
#include "srv/Interface.hpp"

typedef srv::interface InterfaceObject; //service interface

class ServiceNode : public rclcpp::Node
{
    public:
        ServiceNode() : Node("service_server_node_name")
        {
            service_server_ = this->create_service<InterfaceObject>(
                "service_name",
                std::bind(&ServiceNode::service_method, this, 
                    std::placeholders::_1, std::placeholders::_2
                )
            );
        }
    
    private:
        rclcpp::Service<InterfaceObject>::SharedPtr service_server_;

        void service_method(
            const InterfaceObject::Request::SharedPtr request,
            InterfaceObject::Response::SharedPtr response
        ){
            // ** Do anything
        }
};

int main(int argc, char * argv[]){

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServiceNode>());
    rclcpp::shutdown();

    return 0;
}
