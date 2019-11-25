cmake_minimum_required(VERSION 3.15)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c++14")
add_executable(GeneticAlgorithm main.cpp)