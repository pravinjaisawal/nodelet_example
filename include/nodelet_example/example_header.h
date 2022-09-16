#pragma once
#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <sstream>
#include "std_msgs/String.h"

namespace learning_nodelet_ns
{
	class SubPubNodeletClass : public nodelet::Nodelet
	{
		public:
			SubPubNodeletClass();
			~SubPubNodeletClass();
			void personCallback(const std_msgs::String::ConstPtr& msg);
		private:
			ros::Publisher pub;
			ros::Subscriber sub;
			virtual void onInit();
			
	}; // end class SubPubNodeletClass
} // end learning_nodelet_ns
