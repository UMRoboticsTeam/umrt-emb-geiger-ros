#ifndef PROJECT_NAME_EXAMPLE_NODE_HPP
#define PROJECT_NAME_EXAMPLE_NODE_HPP

#include "umrt-geiger-interface/geiger.hpp"
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/float32.hpp"
#include <memory>

/**
 * This is an example node provided to demonstrate file structure and CMake configuration.
 */
class GeigerNode: public rclcpp::Node {
public:
    /**
     * Constructs Gieger ROS Node.
     */
    GeigerNode();
    ~GeigerNode(); 



private: 
    std::shared_ptr<Geiger> geiger{nullptr}; 
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr geiger_publisher; 
    void geiger_publisher_cb(double geiger_value); 
}; 
  


#endif //PROJECT_NAME_EXAMPLE_NODE_HPP
