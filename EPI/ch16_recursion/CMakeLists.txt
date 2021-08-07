cmake_minimum_required(VERSION 3.10)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(16_1_towers_of_hanoi 16_1_towers_of_hanoi.cc)
add_executable(16_2_n_attacking_queens 16_2_n_attacking_queens.cc)
add_executable(16_3_generate_permutations 16_3_generate_permutations.cc)
add_executable(16_4_generate_power_set 16_4_generate_power_set.cc)
