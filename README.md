fabio@fabio-VirtualBox:~$ source /opt/ros/melodic/setup.bash
fabio@fabio-VirtualBox:~$ roscore


How to run listener-talker: http://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber



__________________ 1A __________________



Creating a catkin Package
catkin_create_pkg script to create a new catkin package, and what you can do with it after it has been created.

$ cd ~/catkin_ws/src
Now use the catkin_create_pkg script to create a new package called 'beginner_tutorials' which depends on std_msgs, roscpp, and rospy:

$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
This will create a beginner_tutorials folder which contains a package.xml and a CMakeLists.txt, which have been partially filled out with the information you gave catkin_create_pkg.

catkin_create_pkg requires that you give it a package_name and optionally a list of dependencies on which that package depends:




Building a catkin workspace and sourcing the setup file
Now you need to build the packages in the catkin workspace:

$ cd ~/catkin_ws
$ catkin build
After the workspace has been built it has created a similar structure in the devel subfolder as you usually find under /opt/ros/$ROSDISTRO_NAME.

To add the workspace to your ROS environment you need to source the generated setup file:

$ . ~/catkin_ws/devel/setup.bash




Running the Publisher
Make sure that a roscore is up and running:

$ roscore
catkin specific If you are using catkin, make sure you have sourced your workspace's setup.sh file after calling catkin build but before trying to use your applications:


# In your catkin workspace
$ cd ~/catkin_ws
$ source ./devel/setup.bash
In the last tutorial we made a publisher called "talker". Let's run it:

$ rosrun beginner_tutorials talker      (C++)



Running the Subscriber
In the last tutorial we made a subscriber called "listener". Let's run it:

$ rosrun beginner_tutorials listener     (C++)



__________________ 1B __________________


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
