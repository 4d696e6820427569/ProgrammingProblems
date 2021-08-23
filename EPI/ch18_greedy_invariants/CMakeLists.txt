cmake_minimum_required(VERSION 3.10)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(3_sum 3_sum.cc)
