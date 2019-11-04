# ENPM808X- ROS Beginner tutorials-ROS Services, Logging and Launch files
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
## Using service call to change the input string
After following installation, compilation directions and launch file compilation instructions execute the following in a new terminal
```
source ./devel/setup.bash
rosservice call /Changed_String "input: 'I changed the string'"
```
