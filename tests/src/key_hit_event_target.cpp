#include <rclcpp/rclcpp.hpp>
#include "key_event_nodes/key_hit_event_node.hpp"
#include "key_event_msgs/msg/key_event.hpp"


class SubNode : public rclcpp::Node{
private:
  rclcpp::Subscription<key_event_msgs::msg::KeyEvent>::SharedPtr sub_;
public:
  SubNode(
    const std::string& name_space="", 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  ):Node("key_hit_event_test_sub_node",name_space,options){
    sub_ = this->create_subscription<key_event_msgs::msg::KeyEvent>(
      "key_hit_event",
      rclcpp::QoS(10),
      [this](const key_event_msgs::msg::KeyEvent::SharedPtr msg) ->void {
        RCLCPP_INFO(this->get_logger(), "subscriber:key:%c", msg->key);
      }
    );
  }
};


int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  auto node1 = std::make_shared<key_event::KeyHitEventNode>();
  exec.add_node(node1);
  auto node2 = std::make_shared<SubNode>();
  exec.add_node(node2);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
