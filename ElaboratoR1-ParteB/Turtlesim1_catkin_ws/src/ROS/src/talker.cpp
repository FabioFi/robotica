#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;

void move(double speed, double distance, bool isForward);

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  double speed = 0;
  double distance = 0;
  bool isForward = true;
  
  //ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  ROS_INFO("\n***********START TURTLEBOT*************");
  move(speed, distance, isForward);

  //ros::spinOnce();
  ros::spin();

  return 0;
}
// %EndTag(FULLTEXT)%

void move(double speed, double distance, bool isForward){
  // geometry_msg/twist <- turtle1/cmd_vel
  geometry_msgs::Twist vel_msg;

  vel_msg.linear.x = 2;
  vel_msg.linear.y = 0;
  vel_msg.linear.z = 0;

  vel_msg.angular.x = 0;
  vel_msg.angular.y = 0;
  vel_msg.angular.z = 1.8;

  //ros::Rate loop_rate(10);
  //do{
  velocity_publisher.publish(vel_msg);
  //}while(true);

}
