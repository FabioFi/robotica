Create new package named ROS



Create SRC folder (similar to talker or listener)



Look for the topic & package
$ rosrun turtlesim turtlesim_node
$ rostopic list

/rosout
/rosout_agg
/turtle1/cmd_vel
/turtle1/color_sensor
/turtle1/pose

$ rostopic info /turtle1/cmd_vel

Type: geometry_msgs/Twist
Publishers: None
Subscribers:
 * /turtlesim (http://fabio-VirtualBox:41169/)

$ rosmsg show geometry_msgs/Twist

geometry_msgs/Vector3 linear
  float64 x
  float64 y
  float64 z
geometry_msgs/Vector3 angular
  float64 x
  float64 y
  float64 z



EXECUTE
$ roscore

$ rosrun turtlesim turtlesim_node

$ catkin build

$ source ./devel/setup.bash

$ rosrun ROS talker
