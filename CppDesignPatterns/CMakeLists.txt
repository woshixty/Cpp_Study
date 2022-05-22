cmake_minimum_required(VERSION 3.20)
project(CppDesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppDesignPatterns main.cpp)
add_executable(factory factory/Product.cpp factory/Product.h factory/Factory.cpp factory/Factory.h factory/main.cpp)
add_executable(builder builder/main.cpp builder/Product.cpp builder/Product.h builder/Builder.cpp builder/Builder.h builder/Director.cpp builder/Director.h)
add_executable(week03 week03/main.cpp week03/Shape.h week03/Triangle.cpp week03/Triangle.h week03/Square.cpp week03/Square.h week03/Rectangle.cpp week03/Rectangle.h week03/Trapezium.cpp week03/Trapezium.h week03/Round.cpp week03/Round.h week03/Compoundshape.cpp week03/Compoundshape.h week03/CompoundshapeBuilder.cpp week03/CompoundshapeBuilder.h week03/ShapeFactory.cpp week03/ShapeFactory.h)
add_executable(week04 week04/main.cpp week04/kMatrixVectorSource.h week04/kMatrix.h week04/kMatrixVector.h week04/kMatrixMap.h week04/kMatrixIterator.h)
add_executable(singleton singleton/Singleton.cpp singleton/Singleton.h)
add_executable(testVector week04/TestVector.cpp week04/kMatrixVector.h week04/kMatrixMap.h week04/kMatrix.h)
add_executable(testMap week04/TestMap.cpp week04/kIterator.h)