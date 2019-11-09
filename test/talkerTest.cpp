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

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros/service_client.h>
#include <beginner_tutorials/Change_String.h>

/*
 * @brief: This test suite checks whether or not the service exists
 *         and if it exists checks whether the string is replaced by
 *         the service call or not
 * @param: TESTSuite: name of the test case
 * @param: checkServices: name of the test
 * @return: none
 */

TEST(TESTSuite , checkServices) {
  ros::NodeHandle nh;
  ros::ServiceClient client = nh
      .serviceClient<beginner_tutorials::Change_String>("Changed_String");
  EXPECT_TRUE(client.waitForExistence(ros::Duration(3)));

  beginner_tutorials::Change_String srv;
  /* Check to see if the client is being called properly*/
  srv.request.input = "Test String";
  EXPECT_TRUE(client.call(srv));

  // Check to see if the input and output strings are equal
  EXPECT_STREQ(srv.request.input.c_str(), srv.response.output.c_str());
}
