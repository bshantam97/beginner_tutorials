/**
 * MIT License

 Copyright (c) [2019] [Shantam Bajpai]

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

/*Include header files.....................................................*/
#include <beginner_tutorials/Change_String.h>
#include <sstream>
#include "changeString.hpp"
#include <tf/transform_broadcaster.h>
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
  /*The node initialization*/
  ros::init(argc, argv, "talker");
  /*Creating an object for the nodeHandle class which is
   used as the access point for communcation
   */
  ros::NodeHandle nh_;
  /*message frequency*/
  int freq = 20;
  /*Initialize counter*/
  int count = 0;
  /*Inputs the frequency*/
  if (argc > 1) {
    // converts string argument to int
    freq = atoi(argv[1]);
  }
  ROS_DEBUG_STREAM("The frequency has been set" << freq);
  /*Check for negative input frequency*/
  if (freq < 0) {
    ROS_ERROR_STREAM("The frequency cannot be less than 0");
    /*Set an arbitrary value of frequency to make it positive*/
    freq = 2;
    ROS_INFO_STREAM(
        "The frequency value is changed so as to print out "
                    "messages with a low frequency rate");
  }
  /*Check whether the frequency is above 0 or not*/
  if (freq == 0) {
    ROS_FATAL_STREAM("The frequency cannot be zero as then no "
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
  /*Declaring a broadcaster object, provides an easy way to publish
   co-ordinate frame transform information
   */
  static tf::TransformBroadcaster tbr;

  /*Transform object*/
  tf::Transform transform;
  while (ros::ok()) {

    /*Set the translational element*/
    transform.setOrigin(tf::Vector3(1, 1, 1));

    /*Declare Quaternion object*/
    tf::Quaternion q;

    /*Set quaternion using fixed axis RPY*/
    q.setRPY(0, 0, 40);

    /*Set the rotational element by quaternion*/
    transform.setRotation(q);

    /*
     * @param: "world": name of the parent frame
     * @param: "talk": name of the child frame
     */
    tbr.sendTransform(
        tf::StampedTransform(transform, ros::Time::now(), "world", "talk"));

    /*message string*/
    std_msgs::String msg;
    std::stringstream ss;
    ss << stringChange << count;
    msg.data = ss.str();
    /*prints out the string*/
    ROS_INFO_STREAM(msg.data.c_str() << count);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}
