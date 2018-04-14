cmake_minimum_required(VERSION 2.8.3)
set(CMAKE_CXX_STANDARD 14)

project(homework1)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    message_generation
    )

add_message_files(
    FILES
    student.msg
    )

generate_messages(
    DEPENDENCIES
    std_msgs
    )

catkin_package(CATKIN_DEPENDS roscpp std_msgs message_runtime)

include_directories(
    ${catkin_INCLUDE_DIRS}
    )

add_executable(${PROJECT_NAME}_talker src/talker.cpp)
target_link_libraries(${PROJECT_NAME}_talker ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_talker homework1_generate_messages_cpp)
set_target_properties(${PROJECT_NAME}_talker
    PROPERTIES OUTPUT_NAME talker
    PREFIX "")

add_executable(${PROJECT_NAME}_listener src/listener.cpp)
target_link_libraries(${PROJECT_NAME}_listener ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_listener homework1_generate_messages_cpp)
set_target_properties(${PROJECT_NAME}_listener
    PROPERTIES OUTPUT_NAME listener
    PREFIX "")

add_executable(${PROJECT_NAME}_filter src/filter.cpp)
target_link_libraries(${PROJECT_NAME}_filter ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_filter homework1_generate_messages_cpp)
set_target_properties(${PROJECT_NAME}_filter
    PROPERTIES OUTPUT_NAME filter
    PREFIX "")
