#include "umrt_geiger_ros/geiger_node.hpp"
#include <thread>


GeigerNode::GeigerNode(const std::string& serial_addr, size_t serial_buffer_size):
Node("geiger_node"),geiger(serial_addr)
{
    
    geiger.geiger_data.connect([](const std::string & geiger_msg){geiger_publisher_cb(geiger_msg);})
    
    std::thread read_thread([&](){
        geiger.read_geiger(serial_buffer_size); 
    })
}

void GeigerNode::geiger_publisher_cb(const std::string& geiger_msg){
    std_msg::msg::String msg; 
    msg.data = geiger_msg; 
    geiger_publisher -> publish(msg);  
}           