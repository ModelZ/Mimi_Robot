#include "rclcpp/rclcpp.hpp"
#include "srv/Interface.hpp"

#include <iostream>

typedef project1::srv::Interface InterfaceObject;

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto service_client_node = rclcpp::Node::make_shared("service_client_node_name"); //create client service node

    auto client = service_client_node->create_client<InterfaceObject>("odd_even_check"); //create client

    auto request = std::make_shared<InterfaceObject::Request>();

    std::cout << "Please type a number to check if it is Odd or Even: ";
    std::cin >> request->number;

    client->wait_for_service();
    auto result = client->async_send_request(request);

    if(rclcpp::spin_until_future_complete(service_client_node, result) == rclcpp::FutureReturnCode::SUCCESS) //request complete
    {
        // ** do anything

    } else {
        std::cout << "there was an error processing the request..." << std::endl;
    }

    rclcpp::shutdown();
}