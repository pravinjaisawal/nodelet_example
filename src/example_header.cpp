#include <nodelet_example/example_header.h>
#include <pluginlib/class_list_macros.h>

namespace learning_nodelet_ns
{
SubPubNodeletClass::SubPubNodeletClass()
{
  ROS_INFO("SampleNodeletClass Constructor");
}

SubPubNodeletClass::~SubPubNodeletClass()
{
  ROS_INFO("SampleNodeletClass Destructor");
}

void SubPubNodeletClass::onInit()
{
    NODELET_INFO("SampleNodeletClass - %s", __FUNCTION__);
    ros::NodeHandle& public_nh = getNodeHandle();
    ros::NodeHandle& private_nh = getPrivateNodeHandle();
    sub = private_nh.subscribe("person", 1000, &SubPubNodeletClass::personCallback, this);
    pub = private_nh.advertise<std_msgs::String>("hello_person", 1000);
}

void SubPubNodeletClass::personCallback(const std_msgs::String::ConstPtr& msg)
{
	std_msgs::String msg2;
	std::stringstream ss;
    ss << "hello " << msg->data.c_str();
    msg2.data = ss.str();
    pub.publish(msg2);
}
} // namespace example_ns

PLUGINLIB_EXPORT_CLASS(learning_nodelet_ns::SubPubNodeletClass, nodelet::Nodelet)
