#include <bibola/bibola.hpp>

namespace bibola {

BiBoLa::BiBoLa() : Node("bibola_node") {
  RCLCPP_INFO(this->get_logger(), "Starting bibola_node...");
}

void BiBoLa::log_foo_param() {
  RCLCPP_INFO(this->get_logger(), "Hello World!!11elf");
}
}  // namespace bibola

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<bibola::BiBoLa>();

  rclcpp::Duration timer_duration = rclcpp::Duration::from_seconds(1.0);
  rclcpp::TimerBase::SharedPtr timer =
      rclcpp::create_timer(node, node->get_clock(), timer_duration, [node]() -> void { node->log_foo_param(); });
  rclcpp::experimental::executors::EventsExecutor exec;
  exec.add_node(node);

  exec.spin();
  rclcpp::shutdown();
}
