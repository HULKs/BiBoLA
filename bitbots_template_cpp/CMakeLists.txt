cmake_minimum_required(VERSION 3.5)
project(bibola)

# Add support for C++17
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif ()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include)

add_compile_options(-Wall -Werror -Wno-unused)

add_executable(bibola src/bibola.cpp)

target_link_libraries(
  bibola
  rclcpp::rclcpp
  bibola_parameters
)

## Specify libraries to link a library or executable target against
ament_target_dependencies(
  bibola
  ament_cmake
  rclcpp
)

install(TARGETS bibola
        DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
        DESTINATION share/${PROJECT_NAME})

ament_package()
