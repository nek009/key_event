#ifndef KEY_EVENT_NODES__KEY_HIT_EVENT_NODE_HPP
#define KEY_EVENT_NODES__KEY_HIT_EVENT_NODE_HPP


#include <rclcpp/rclcpp.hpp>
#include "visibility.h"
#include "key_event_msgs/msg/key_event.hpp"

namespace key_event{

class KeyHitEventNode : public rclcpp::Node{
public:
  KEY_EVENT_NODES_PUBLIC
  KeyHitEventNode(
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );


  KEY_EVENT_NODES_PUBLIC
  KeyHitEventNode(
    const std::string& name_space,
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

} // end of namespace

#endif


