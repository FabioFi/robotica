// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

// %Tag(CALLBACK)%
void poseCallback(const turtlesim::PoseConstPtr& msg){
  ROS_INFO("x: %.2f, y: %.2f", msg->x, msg->y);
}
// %EndTag(CALLBACK)%

int main(int argc, char **argv){

  const double FORWARD_SPEED_MPS = 2.0;
  const double ROUND_SPEED_MPS = 1.8;

  /**
  * The ros::init() function needs to see argc and argv so that it can perform
  * any ROS arguments and name remapping that were provided at the command line.
  * For programmatic remappings you can use a different version of init() which takes
  * remappings directly, but for most command-line programs, passing argc and argv is
  * the easiest way to do it.  The third argument to init() is the name of the node.
  *
  * You must call one of the versions of ros::init() before using any other
  * part of the ROS system.
  */
  ros::init(argc, argv, "move_turtle");

  /**
  * NodeHandle is the main access point to communications with the ROS system.
  * The first NodeHandle constructed will fully initialize this node, and the last
  * NodeHandle destructed will close down the node.
  */
  ros::NodeHandle node;

  /**
  * The advertise() function is how you tell ROS that you want to
  * publish on a given topic name. This invokes a call to the ROS
  * master node, which keeps a registry of who is publishing and who
  * is subscribing. After this advertise() call is made, the master
  * node will notify anyone who is trying to subscribe to this topic name,
  * and they will in turn negotiate a peer-to-peer connection with this
  * node.  advertise() returns a Publisher object which allows you to
  * publish messages on that topic through a call to publish().  Once
  * all copies of the returned Publisher object are destroyed, the topic
  * will be automatically unadvertised.
  *
  * The second parameter to advertise() is the size of the message queue
  * used for publishing messages.  If messages are published more quickly
  * than we can send them, the number here specifies how many messages to
  * buffer up before throwing some away.
  */
  // %Tag(PUBLISHER)%
  ros::Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
  // %EndTag(PUBLISHER)%

  /**
  * The subscribe() call is how you tell ROS that you want to receive messages
  * on a given topic.  This invokes a call to the ROS
  * master node, which keeps a registry of who is publishing and who
  * is subscribing.  Messages are passed to a callback function, here
  * called chatterCallback.  subscribe() returns a Subscriber object that you
  * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
  * object go out of scope, this callback will automatically be unsubscribed from
  * this topic.
  *
  * The second parameter to the subscribe() function is the size of the message
  * queue.  If messages are arriving faster than they are being processed, this
  * is the number of messages that will be buffered up before beginning to throw
  * away the oldest ones.
  */
  // %Tag(SUBSCRIBER)%
  //se voglio stampare la posizione
  ros::Subscriber sub = node.subscribe("turtle1/pose", 10, poseCallback);

  // The default constructor will set all commands to 0
  geometry_msgs::Twist msg;
  msg.linear.x = FORWARD_SPEED_MPS;
  msg.angular.z = ROUND_SPEED_MPS;

  // Loop at 10Hz, publishing movement commands until we shut down
  ros::Rate rate(10);
  ROS_INFO("---------- Starting to move forward ----------");
  while (ros::ok()) {
  pub.publish(msg);

  // %Tag(SPINONCE)%
  ros::spinOnce(); // Allow processing of incoming messages
  // %EndTag(SPINONCE)%

  // %Tag(RATE_SLEEP)%
  rate.sleep();
  // %EndTag(RATE_SLEEP)%
  }
}
