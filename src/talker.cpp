#include <ros/ros.h>
#include "homework1/student.h"

#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <cstdint>

int main(int argc, char **argv) {
    ROS_INFO("STARTED TALKER");

    ros::init(argc, argv, "talker");

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<homework1::student>("chatter", 1);

    // one message every second
    ros::Rate loop_rate(1);

    std::srand(std::time(nullptr));

    std::vector<std::tuple<std::string, uint8_t, std::string>> messages = {
        std::make_tuple("Mirko", 21, "Computer Science"),
        std::make_tuple("Eliana", 21, "Bioinformatics"),
        std::make_tuple("Irene", 21, "Biotechnology"),
        std::make_tuple("Davide", 21, "Mathematics")
    };

    homework1::student msg;

    while (ros::ok()) {
        std::tie(msg.name, msg.age, msg.cdl) = messages[std::rand() % messages.size()];
        /* ROS_INFO("msg sent: %s - %d - %s", msg.name.c_str(), msg.age, msg.cdl.c_str()); */

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
