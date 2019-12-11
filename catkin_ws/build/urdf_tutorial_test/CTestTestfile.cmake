# CMake generated Testfile for 
# Source directory: /home/fabio/catkin_ws/src/urdf_tutorial_test
# Build directory: /home/fabio/catkin_ws/build/urdf_tutorial_test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_urdf_tutorial_test_roslaunch-check_launch "/home/fabio/catkin_ws/build/urdf_tutorial_test/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/fabio/catkin_ws/build/urdf_tutorial_test/test_results/urdf_tutorial_test/roslaunch-check_launch.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/fabio/catkin_ws/build/urdf_tutorial_test/test_results/urdf_tutorial_test" "/opt/ros/melodic/share/roslaunch/cmake/../scripts/roslaunch-check -o '/home/fabio/catkin_ws/build/urdf_tutorial_test/test_results/urdf_tutorial_test/roslaunch-check_launch.xml' '/home/fabio/catkin_ws/src/urdf_tutorial_test/launch' ")
subdirs("gtest")
