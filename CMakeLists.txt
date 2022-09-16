cmake_minimum_required(VERSION 3.0.2)
project(nodelet_example)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  std_msgs
)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS nodelet roscpp std_msgs
#  DEPENDS system_lib
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
 add_library( pubsubnodelet
   src/example_header.cpp
 )


add_executable(name_publisher src/name_publisher.cpp)
target_link_libraries(name_publisher ${catkin_LIBRARIES})


## Specify libraries to link a library or executable target against
target_link_libraries(pubsubnodelet
   ${catkin_LIBRARIES}
)

if(catkin_EXPORTED_LIBRARIES)
  add_dependencies(pubsubnodelet ${catkin_EXPORTED_LIBRARIES})
endif()

