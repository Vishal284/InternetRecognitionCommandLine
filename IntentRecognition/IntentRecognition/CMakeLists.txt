# CMakeList.txt : CMake project for IntentRecognition, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("IntentRecognition")

# Add source to this project's executable.
add_executable (IntentRecognition "IntentRecognition.cpp" "IntentRecognition.h"  "main.cpp")

# TODO: Add tests and install targets if needed.
