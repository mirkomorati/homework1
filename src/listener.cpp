#include <ros/ros.h>
#include <std_msgs/Char.h>
#include "homework1/student.h"
#include <sstream>

struct filterStatus {
    char status;

    void changeStatusCallback(const std_msgs::Char::ConstPtr &msg) {
        switch (msg->data) {
            case 'a':
            case 'n':
            case 'e':
            case 'c':
                status = msg->data;
                break;
            default:
                ROS_INFO("Invalid status");
                break;
        }
    }

    void chatterCallback(const homework1::student::ConstPtr &msg) {
        switch (status) {
            case 'a':
                ROS_INFO("Received: %s - %d - %s", msg->name.c_str(), msg->age, msg->cdl.c_str());
                break;
            case 'n':
                ROS_INFO("Received: %s", msg->name.c_str());
                break;
            case 'e':
                ROS_INFO("Received: %d", msg->age);
                break;
            case 'c':
                ROS_INFO("Received: %s", msg->cdl.c_str());
                break;
            default:
                ROS_INFO("Invalid status");
                break;
        }
    }
};

int main(int argc, char **argv) {
    ROS_INFO("STARTED LISTENER");

    ros::init(argc, argv, "listener");

    ros::NodeHandle n;

    filterStatus s;
    s.status = 'a';
    ros::Subscriber filter_sub = n.subscribe("filter", 1, &filterStatus::changeStatusCallback, &s);

    ros::Subscriber chatter_sub = n.subscribe("chatter", 1, &filterStatus::chatterCallback, &s);

    ros::spin();
    return 0;
}
