cmake_minimum_required(VERSION 3.10)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(15_1_validate_bst_property 15_1_validate_bst_property.cc)
add_executable(15_2_find_first_key_greater 15_2_find_first_key_greater.cc)
add_executable(15_3_k_largest_element_in_bst 15_3_k_largest_element_in_bst.cc)
