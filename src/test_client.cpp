/*
 * test_client.cpp
 *
 *  Created on: May 27, 2018
 *      Author: usrc
 */




/*
 * add_3_ints_client.cpp
 *
 *  Created on: May 20, 2018
 *      Author: usrc
 */


#include "ros/ros.h"
#include "chapter2_tutorials/chapter2_srv1.h"
#include <sstream>




int main(int argc, char **argv) {
	ros::init(argc, argv, "test_client");
	if(argc != 4) {
		ROS_INFO("usage: add_3_ints_client A B C ");
		return 1;
	}


	ros::NodeHandle n;

	ros::ServiceClient client = n.serviceClient<chapter2_tutorials::chapter2_srv1>("add_3_ints");

	chapter2_tutorials::chapter2_srv1 srv;

	srv.request.A = atoll(argv[1]);
	srv.request.B = atoll(argv[2]);
	srv.request.C = atoll(argv[3]);

	if(client.call(srv)) {
		ROS_INFO("Sum: %d", (long int)srv.response.sum);

	}
	else {
		ROS_ERROR("Failed to call service add_3_inits");
	}

	return 0;


	ROS_INFO("Ready to add 3 ints.");
	ros::spin();


	return 0;
}

