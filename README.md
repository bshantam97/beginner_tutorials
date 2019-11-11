# ENPM808X- ROS Beginner tutorials-ROS TF, Unit testing and Bag files
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](LICENSE.md)

## Dependencies
[![ROS Kinetic Installation](https://img.shields.io/badge/ROSKinetic-Clickhere-brightgreen.svg?style=flat)](http://wiki.ros.org/kinetic/Installation)

## Standard install via command-line
```
cd ~/catkin_ws/src
mkdir beginner_tutorials
cd beginner_tutorials
git clone --recursive https://github.com/bshantam97/beginner_tutorials.git
cd ../..
catkin_make 

```
## Using launch files to change the frequency of output messages
### Using roslaunch without any argument
After following the directions above follow the directions to run using roslaunch below
```
source ./devel/setup.bash
roslaunch beginner_tutorials Week10.launch
```
### Using roslaunch with frequency argument to change output message frequency 
```
source ./devel/setup.bash
roslaunch beginner_tutorials Week10.launch freq:= <input any frequency you like(integer)>
```
### Using service call to change the input string
After following installation, compilation directions and launch file compilation instructions execute the following in a new terminal
```
source ./devel/setup.bash
rosservice call /Changed_String "input: 'I changed the string'"
```
## Running rqt_tf_tree and tf_echo and viewing frames

After launching the Week10.launch file and setting the frequency follow the instructions below to use ROS tf_echo and rqt_tf_tree. 
rqt_tf_tree provides a GUI for visualizing ROS tf frame tree and tf_echo prints the transforms in the terminal

Open 2 new terminals
### Terminal 1
```
source ./devel/setup.bash
rosrun rqt_tf_tree rqt_tf_tree
```
### Terminal 2
```
source ./devel/setup.bash
rosrun tf tf_echo world talk
```
### Terminal 3
```
source ./devel/setup.bash
rosrun tf view_frames
evince frames.pdf
```
## Using launch file to record data and save in a .bag file
Open up a new terminal after closing the above terminals and run the following command to enable or disable creation and recording of data in a bag file. Use "record:=enable" to enable recording and "record:=disable" to disable recording.

```
source ./devel/setup.bash
roslaunch beginner_tutorials Week10.launch freq:=2 record:=<enable/disable>
```
## Using rosbag to and replay topic messages
Open up 3 new terminals for the demonstration of rosbag play
### Terminal 1
In your catkin workspace run the following
```
cd ~/catkin_ws/
roscore
```
### Terminal 2
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials listener
```
### Terminal 3
```
cd ~/catkin_ws/src/beginner_tutorials/beginner_tutorials/results
rosbag play record.bag
```
After running the above commands your should see terminal 3 replaying the bag file and after running the listener node you should see it prints out the topic messages.

## Running Rostests

In your catkin workspace follow the commands given below to run the tests

```
source ./devel/setup.bash
rostest beginner_tutorials test.launch
```
### Sample rostest output
```
... logging to /home/bshantam97/.ros/log/rostest-bshantam97-HP-Pavilion-x360-Convertible-7463.log
[ROSUNIT] Outputting test results to /home/bshantam97/.ros/test_results/beginner_tutorials/rostest-test_test.xml
[Testcase: testtalkerTest] ... ok

[ROSTEST]-----------------------------------------------------------------------

[beginner_tutorials.rosunit-talkerTest/checkServices][passed]
[beginner_tutorials.rosunit-talkerTest/checkString][passed]

SUMMARY
 * RESULT: SUCCESS
 * TESTS: 2
 * ERRORS: 0
 * FAILURES: 0

rostest log file is in /home/bshantam97/.ros/log/rostest-bshantam97-HP-Pavilion-x360-Convertible-7463.log
```
