#ifndef PROJECT_NAME_EXAMPLE_NODE_HPP
#define PROJECT_NAME_EXAMPLE_NODE_HPP

#include "umrt_geiger_interface/geiger.hpp"
#include <rclcpp/rclcpp.hpp>

/**
 * This is an example node provided to demonstrate file structure and CMake configuration.
 */
class GeigerNode: public rclcpp::Node {
public:
    /**
     * Constructs an ExampleNode.
     */
    GeigerNode();

private: 
    Geiger geiger_instance; 
    rclcpp::Publisher<std_msgs::msg::string>::SharedPtr geiger_publisher; 
    rclcpp::TimerBase::SharedPtr timer; 
    std::chrono::duration<int,std::milli> timer_duration{}; 
}
  


#endif //PROJECT_NAME_EXAMPLE_NODE_HPP
