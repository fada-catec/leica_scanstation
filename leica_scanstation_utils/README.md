# Leica Scanstation Utils
This package contains common functions to use in combination with package [leica_scanstation](https://github.com/fada-catec/leica_scanstation) and [leica_pointcloud_processing](https://github.com/fada-catec/leica_point_cloud_processing.git).

The aim is to assist in the program's execution **independently of the OS used**

For example, defining the absolute path to the **/pointclouds** folder, where scans and pointclouds will be stored.

# Usage #
Run the main program to store in ROS Param Server the absolute path to pointcloud folder (`/pointcloud_folder`):

        rosrun leica_scanstation_utils main

## Dependencies
- ROS
- Eigen3