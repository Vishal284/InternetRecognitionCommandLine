﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("IntentRecognition")

# Include sub-projects.
add_subdirectory ("IntentRecognition")
add_subdirectory ("tests")
