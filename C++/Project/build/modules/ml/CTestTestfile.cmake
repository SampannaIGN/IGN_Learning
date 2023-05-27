# CMake generated Testfile for 
# Source directory: /home/sampannat/Downloads/Learning/C++/Project/opencv/modules/ml
# Build directory: /home/sampannat/Downloads/Learning/C++/Project/build/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/home/sampannat/Downloads/Learning/C++/Project/build/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/home/sampannat/Downloads/Learning/C++/Project/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/sampannat/Downloads/Learning/C++/Project/opencv/cmake/OpenCVUtils.cmake;1763;add_test;/home/sampannat/Downloads/Learning/C++/Project/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/sampannat/Downloads/Learning/C++/Project/opencv/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/sampannat/Downloads/Learning/C++/Project/opencv/modules/ml/CMakeLists.txt;2;ocv_define_module;/home/sampannat/Downloads/Learning/C++/Project/opencv/modules/ml/CMakeLists.txt;0;")
