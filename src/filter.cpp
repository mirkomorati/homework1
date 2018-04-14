#include <ros/ros.h>
#include <std_msgs/Char.h>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    ROS_INFO("STARTED FILTER");
    ros::init(argc, argv, "filter");

    ros::NodeHandle n;

    ros::Publisher filter_pub = n.advertise<std_msgs::Char>("filter", 1);

    ros::Rate loop_rate(1);

    std::cout << "'a': show all\n'n': show name\n'e': show age\n'c': show course\n";
    
    std_msgs::Char msg;
    while(std::cout << "> ", std::cin >> msg.data) {
        ros::spinOnce();
        filter_pub.publish(msg);
    }
}
