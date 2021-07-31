cmake_minimum_required(VERSION 3.10)

# add_library(SINGLY_LINKED_LIST ../data_structures/singly_linked_list.h ../data_structures/singly_linked_list.cc)

# add_executable(reverse_list reverse_list.cc)
# target_link_libraries(reverse_list DATA_STRUCTURES)

set (INCLUDE_DIR ../data_structures/)
include_directories(${INCLUDE_DIR})

add_executable(find_value find_value.cc)
# target_link_libraries(find_value BST_NODE)

add_executable(bst_to_linked_list bst_to_linked_list.cc)
# target_link_libraries(bst_to_linked_list SINGLY_LINKED_LIST)

add_executable(lca lca.cc)

add_executable(identical_bt identical_bt.cc)

add_executable(minimum_difference minimum_difference.cc)

add_executable(find_the_mode find_the_mode.cc)

add_executable(gather_levels gather_levels.cc)

add_executable(max_value_each_level max_value_each_level.cc)

add_executable(visible_values visible_values.cc)

add_executable(bottoms_up bottoms_up.cc)

add_executable(zigzag_traversal zigzag_traversal.cc)

add_executable(gather_nary_tree_levels gather_nary_tree_levels.cc)

add_executable(gather_columns gather_columns.cc)

add_executable(max_depth max_depth.cc)

add_executable(root_to_leaf_paths root_to_leaf_paths.cc)

add_executable(root_to_leaf_path_sum root_to_leaf_path_sum.cc)

add_executable(validate_bst validate_bst.cc)

add_executable(same_leaves same_leaves.cc)

add_executable(symmetrical_tree symmetrical_tree.cc)

add_executable(sum_left_leaves sum_left_leaves.cc)
