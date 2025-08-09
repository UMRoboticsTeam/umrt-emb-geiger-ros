//
// Created by Toni Odujinrin on 2025-27-06
//

#include "umrt-geiger-ros/geiger-node.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    //spin up Geiger Node
    rclcpp::spin(std::make_shared<GeigerNode>());
    rclcpp::shutdown();
    return 0;
}
