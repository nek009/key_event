#include <rclcpp/rclcpp.hpp>
#include "rclcpp_components/register_node_macro.hpp"
#include "key_event_nodes/key_hit_event_node.hpp"

namespace key_event{

KeyHitEventNode::KeyHitEventNode(
  const rclcpp::NodeOptions& options
): KeyHitEventNode("",options){}


KeyHitEventNode::KeyHitEventNode(
  const std::string& name_space,
  const rclcpp::NodeOptions& options
): Node("key_hit_event_node", name_space, options){
  RCLCPP_INFO(this->get_logger(), "keyhit");
}

} // end of namespace

RCLCPP_COMPONENTS_REGISTER_NODE(key_event::KeyHitEventNode)

