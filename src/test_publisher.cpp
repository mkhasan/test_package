/*
 * test_node.cpp
 *
 *  Created on: May 27, 2018
 *      Author: usrc
 */




#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "chapter2_tutorials/chapter2_msg1.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "test_node");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<chapter2_tutorials::chapter2_msg1>("test_message", 1000);
	ros::Rate loop_rate(10);

	while (ros::ok()) {
		chapter2_tutorials::chapter2_msg1 msg;
		std::stringstream ss;
		ss << " I am the test node ";
		//msg.data = ss.str();
		msg.A = 11;
		msg.B = 12;
		msg.C = 14;
		//ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}


