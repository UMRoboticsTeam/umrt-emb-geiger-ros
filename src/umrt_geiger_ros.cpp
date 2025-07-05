//
// Created by Toni Odujinrin on 2025-27-06
//

#include <rclcpp/rclcpp.hpp>
#include "umrt_geigerros/geiger_node.hpp"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    
    //create temporary node to get cli args 
    auto temp_node = std::make_shared<rclcpp::Node>("temp");
    temp_node->declare_parameter("serial_addr", "/dev/ttyACM0");
    temp_node->declare_parameter("buffer_size",1000); 
    auto buffer_size = temp_node->get_parameter("buffer_size");
    auto serial_addr = temp_node->get_parameter("serial_addr"); 
    
    //spin up Geiger Node
    rclcpp::spin(std::make_shared<GiegerNode>(serial_addr, buffer_size));
    rclcpp::shutdown();
    return 0;
}