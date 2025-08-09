#include "umrt-geiger-ros/geiger-node.hpp"
#include <thread>


GeigerNode::GeigerNode() : Node("geiger_node") {

    this->declare_parameter("serial_addr", "/dev/ttyACM0");
    this->declare_parameter("buffer_size", 1000);
    this->declare_parameter("baud_rate",115200); 

    size_t buffer_size{ this->get_parameter("buffer_size").as_int()}; 
    std::string serial_addr{ this->get_parameter("serial_addr").as_string()};
    unsigned int baud_rate{this->get_parameter("baud_rate").as_int()}; 

    geiger_publisher = create_publisher<std_msgs::msg::Float32>("geiger_data",10); 
    geiger = std::make_shared<Geiger>(serial_addr,baud_rate);
    this->geiger->geiger_data.connect([this](double geiger_value) {this->geiger_publisher_cb(geiger_value); }); 

    std::thread read_thread([this, &buffer_size]() { this->geiger->read_geiger(buffer_size); }); 
    read_thread.join(); 
}

GeigerNode::~GeigerNode() {
    if (geiger) {
        geiger->stop_read_geiger();  // stop read loop
    }
}

void GeigerNode::geiger_publisher_cb(double geiger_value) {
    std_msgs::msg::Float32 value;
    value.data = geiger_value;
    geiger_publisher->publish(value);
}
