cmake_minimum_required(VERSION 3.8)
project(Lesson5_PIDControl)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp parameter.h PID.cpp PID.h XY.cpp XY.h)
add_executable(Lesson5_PIDControl ${SOURCE_FILES})