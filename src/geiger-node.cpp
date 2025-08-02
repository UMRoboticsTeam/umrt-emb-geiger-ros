#include "umrt-geiger-ros/geiger-node.hpp"
#include <thread>


GeigerNode::GeigerNode() : Node("geiger-node") {

    this->declare_parameter("serial_addr", "/dev/ttyACM0");
    this->declare_parameter("buffer_size", 1000);

    size_t buffer_size{ this->get_parameter("buffer_size") };
    std::string serial_addr{ this->get_parameter("serial_addr") };

    geiger = std::make_shared<Geiger>(serial_addr, buffer_size);
    geiger->geiger_data.connect([](double geiger_value) { geiger_publisher_cb(geiger_value); })

            std::thread read_thread([&]() { geiger.read_geiger(serial_buffer_size); })
}

void GeigerNode::geiger_publisher_cb(double geiger_value) {
    std_msg::msg::Float32 value;
    value.data = geiger_value;
    geiger_publisher->publish(value);
}