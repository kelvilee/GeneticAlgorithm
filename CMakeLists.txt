cmake_minimum_required(VERSION 3.15)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c++14")
add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.cpp Tour.hpp Population.cpp Population.hpp TourManager.cpp TourManager.hpp GenericAlgorithm.cpp GenericAlgorithm.hpp)