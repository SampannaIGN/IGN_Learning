# CMake generated Testfile for 
# Source directory: /home/sampannat/Downloads/Learning/C++/Project/opencv/modules/highgui
# Build directory: /home/sampannat/Downloads/Learning/C++/Project/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/home/sampannat/Downloads/Learning/C++/Project/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/home/sampannat/Downloads/Learning/C++/Project/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/sampannat/Downloads/Learning/C++/Project/opencv/cmake/OpenCVUtils.cmake;1763;add_test;/home/sampannat/Downloads/Learning/C++/Project/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/sampannat/Downloads/Learning/C++/Project/opencv/modules/highgui/CMakeLists.txt;309;ocv_add_accuracy_tests;/home/sampannat/Downloads/Learning/C++/Project/opencv/modules/highgui/CMakeLists.txt;0;")
