/**@copyright  MIT License (c) 2019 Shantam Bajpai
 * @file        main.cpp
 * @author      Shantam Bajpai
 * @brief       Implementation for the publisher
 */

/*Include header files.....................................................*/
#include <beginner_tutorials/Change_String.h>
#include <sstream>
#include "changeString.hpp"
#include "ros/ros.h"
/*
 * @brief: This is a boolean function that is used to change the string values
 * @param: srv::Request- The request part of the srv folder
 * @param: srv::Respond- Responding to a request in the srv folder
 */
bool changeString(beginner_tutorials::Change_String::Request &request,
                  beginner_tutorials::Change_String::Response &response) {
  response.output = request.input;
  stringChange = response.output;
  ROS_WARN_STREAM("The string is being changed due to a service call");
  return true;
}

int main(int argc, char** argv) {
  // The node initialization
  ros::init(argc, argv, "talker");
  /*Creating an object for the nodeHandle class which is
   used as the access point for communcation
   */
  ros::NodeHandle nh_;
  // message frequency
  int freq = 20;
  // Initialize counter
  int count = 0;
  // Inputs the frequency
  freq = atoi(argv[1]);
  ROS_DEBUG_STREAM("The frequency has been set" << freq);
  // Check for negative input frequency
  if (freq < 0) {
    ROS_ERROR_STREAM("The frequency cannot be less than 0");
    // Set an arbitrary value of frequency to make it positive
    freq = 2;
    ROS_INFO_STREAM(
        "The frequency value is changed so as to print out "
                    "messages with a low frequency rate");
  }
  // Check whether the frequency is above 0 or not
  if (freq == 0) {
    ROS_FATAL_STREAM(
        "The frequency cannot be zero as then no "
                     "messages will be printed");
    /**
     * As frequency is zero the system command will
     * kill the nodes and force ros to shutdown
     */
    system("rosnode kill /talker");
    system("rosnode kill /listener");
    ros::shutdown();
  }
  ros::Publisher chatter_pub = nh_.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = nh_.advertiseService("Changed_String",
                                                    changeString);
  /**
   * In the loop_rate object the variable freq has been input
   * to change the output frequency of the messasged being printed
   */
  ros::Rate loop_rate(freq);
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << stringChange << count;
    msg.data = ss.str();
    ROS_INFO_STREAM(msg.data.c_str() << count);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}
