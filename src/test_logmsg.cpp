/*
 * test_logmsg.cpp
 *
 *  Created on: May 28, 2018
 *      Author: usrc
 */



#include "ros/ros.h"
#include "std_msgs/String.h"

#include <ros/console.h>

int main(int argc, char **argv) {


	if( ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug) ) {
	   ros::console::notifyLoggerLevelsChanged();
	}

	ROS_DEBUG("I am DEBUG msg \n");
	ROS_INFO("I am INFO msg \n");
	ROS_WARN("I am WARN msg \n");
	ROS_ERROR("I am ERROR msg \n");
	ROS_FATAL("I am FATAL msg \n");

	int x = -1, i;

	ROS_DEBUG_COND(x < 0, "Uh oh, x = %d, this is bad", x);


	for (i = 0; i < 10; ++i) {
		ROS_DEBUG_ONCE("This message will only print once %d", i);
	}

	ROS_DEBUG_ONCE("This message will only print once %d", i);
	ROS_DEBUG_ONCE("This message will only print once %d", i);
	return 0;

}



