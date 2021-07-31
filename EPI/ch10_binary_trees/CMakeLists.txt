cmake_minimum_required(VERSION 3.10)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(10_1_is_height_balanced 10_1_is_height_balanced.cc)
add_executable(10_4_lca_parent 10_4_lca_parent.cc)
add_executable(10_11_const_space_tree_traversal 10_11_const_space_tree_traversal.cc)
add_executable(10_12_reconstruct_bt_from_pre_in_post 10_12_reconstruct_bt_from_pre_in_post.cc)
