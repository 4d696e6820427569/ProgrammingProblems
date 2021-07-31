cmake_minimum_required(VERSION 3.10)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(9_1_max_stack 9_1_max_stack.cc)
add_executable(9_7_binary_tree_nodes_inorder_increasing_depth 9_7_binary_tree_nodes_inorder_increasing_depth.cc)
add_executable(9_2_evaluate_rpn_expressions 9_2_evaluate_rpn_expressions.cc)
add_executable(9_8_circular_queue 9_8_circular_queue.cc)
add_executable(9_3_wellformedness 9_3_wellformedness.cc)
add_executable(9_9_queue_stacks 9_9_queue_stacks.cc)
