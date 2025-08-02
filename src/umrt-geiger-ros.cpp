//
// Created by Toni Odujinrin on 2025-27-06
//

#include "umrt_geigerros/geiger_node.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    //spin up Geiger Node
    rclcpp::spin(std::make_shared<GiegerNode>(serial_addr, buffer_size));
    rclcpp::shutdown();
    return 0;
}