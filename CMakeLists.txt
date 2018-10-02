cmake_minimum_required(VERSION 3.12)
project(cpp_yellow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -pedantic -O0")

message("CMAKE_CXX_FLAGS_DEBUG:  ${CMAKE_CXX_FLAGS_DEBUG}")

add_executable(cpp_yellow main.cpp)
add_executable(week1_assignment_1 week1/assignment_1/temperature.cpp)
add_executable(week1_assignment_2 week1/assignment_2/block_weight.cpp)