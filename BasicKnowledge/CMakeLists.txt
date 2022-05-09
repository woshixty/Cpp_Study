cmake_minimum_required(VERSION 3.20)
project(BasicKnowledge)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(chapter16 chapter16/main.cpp)
add_executable(16-1 chapter16/16-1.cpp chapter11/mytime0.cpp chapter11/mytime0.h)