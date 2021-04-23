cmake_minimum_required (VERSION 3.8)

project ("tests")

find_package(Catch2 CONFIG REQUIRED)
add_executable(tests "test.cpp" "../IntentRecognition/IntentRecognition.cpp" "../IntentRecognition/IntentRecognition.h")
target_link_libraries(tests PRIVATE Catch2::Catch2)
