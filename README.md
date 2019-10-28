# ENPM808X- ROS Beginner tutorials (Publisher/Subscriber)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](LICENSE.md)


## Standard install via command-line
```
cd ~/catkin_ws/src
mkdir beginner_tutorials
cd beginner_tutorials
git clone --recursive https://github.com/bshantam97/beginner_tutorials.git
cd ../..
catkin_make 

```
Open 3 terminals, the first to initialize the master node, the second for the talker node and the third for the listener node

## Terminal 1
```
roscore
```

## Terminal 2
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials talker
```

## Terminal 3
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials listener
```
