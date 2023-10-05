# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# * for my own mac
# list(APPEND CMAKE_PREFIX_PATH  "/Users/marshallchen/code/vcpkg/installed/arm64-osx/share/")

# name of the project It is best to use something different from the exe name
project(RGBA_build) 

# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Now we add our target executable and the file it is built from.
add_executable(RGBA)
target_include_directories(RGBA PRIVATE include)
# We now add the source files we want for the project. for now we are going to just add main.cpp
# See here for more details https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/
target_sources(RGBA PRIVATE src/main.cpp)

# test code
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
add_executable(RGBATests)
target_include_directories(RGBATests PRIVATE include)
target_sources(RGBATests PRIVATE tests/RGBATests.cpp)
target_link_libraries(RGBATests PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(RGBATests)
