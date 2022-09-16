#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "name_publisher");
  
  ros::NodeHandle n;

  ros::Publisher name_pub = n.advertise<std_msgs::String>("person", 1000);

  ros::Rate loop_rate(1);

  while (ros::ok())
  { 
    std_msgs::String msg;
    std::stringstream ss;
    ss << "Jack ";
    msg.data = ss.str();

    name_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
