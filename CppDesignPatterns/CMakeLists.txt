cmake_minimum_required(VERSION 3.20)
project(CppDesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppDesignPatterns main.cpp)
add_executable(factory factory/Product.cpp factory/Product.h factory/Factory.cpp factory/Factory.h factory/main.cpp)
add_executable(builder builder/main.cpp builder/Product.cpp builder/Product.h builder/Builder.cpp builder/Builder.h builder/Director.cpp builder/Director.h)
add_executable(singleton singleton/Singleton.cpp singleton/Singleton.h)