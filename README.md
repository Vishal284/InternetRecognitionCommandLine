# InternetRecognitionCommandLine
Command line tool for Intent recognition

It is implemented in Visual studio. 
We can use below commands to compile this code

mkdir build
cd build
cmake -S IntentRecognition -B build
cmake --build build

And then output executable will be created inside the build directory.

IMPORTANT: CMake enviroment variable for Windows and SYSROOT path for Linux should be set correctly.
For the test cases, Catch2 package also should be installed.

Catch2 can be cloned from:
git clone https://github.com/Microsoft/vcpkg.git
and can be installed using below commands
bootstrap-vcpkg.bat
vcpkg integrate install
vpkg install catch2:x64-windows
