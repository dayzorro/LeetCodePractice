cmake_minimum_required(VERSION 3.14)
project(SingleLinkedList)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(include)
include_directories(lib/googletest/include)
# 添加 Google Test 子模块
add_subdirectory(lib/googletest)
# 将源文件添加到这个项目的可执行文件
add_executable(SingleLinkedList src/SingleLinkedList.cpp tests/gtest.cpp)

# 链接 Google Test 到您的测试可执行文件
target_link_libraries(SingleLinkedList gtest gtest_main)

