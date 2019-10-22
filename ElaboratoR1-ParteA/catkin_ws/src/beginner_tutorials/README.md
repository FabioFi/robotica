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
