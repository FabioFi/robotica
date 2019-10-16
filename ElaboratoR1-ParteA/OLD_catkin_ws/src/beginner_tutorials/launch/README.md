In un terminale: roslaunch beginner_tutorials turtlemimic.launch

In un altro terminale: rostopic pub /turtlesim1/turtle1/c_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'

