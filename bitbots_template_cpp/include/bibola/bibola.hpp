#include <rclcpp/experimental/executors/events_executor/events_executor.hpp>
#include <rclcpp/rclcpp.hpp>

namespace bibola {

class BiBoLa : public rclcpp::Node {
 public:
  BiBoLa();
  void log_foo_param();
};

}  // namespace bibola
