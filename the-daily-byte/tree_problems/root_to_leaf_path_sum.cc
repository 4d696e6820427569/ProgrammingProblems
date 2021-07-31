/**
 * The Daily Byte
 * 07/03/2021
 *
 * Given a binary tree and a target, return whether or not there exists a root
 * to leaf path such that all values along the path sum to the target.
 */

#include <cassert>
#include <memory>
#include <cstdio>

#include "../data_structures/bst_node.h"

using std::shared_ptr;
using std::make_shared;

using data_structures::BSTNode;

using pTreeNode = shared_ptr<BSTNode<int>>;

bool exists_root_to_leaf_path_sum_aux(const pTreeNode& root, int sum, int cur_sum)
{
    cur_sum += root->data_;

    if (root->left_ == nullptr && root->right_ == nullptr) return sum == cur_sum;

    bool hasPathSum = false;
    if (root->left_ != nullptr)
        hasPathSum = hasPathSum || exists_root_to_leaf_path_sum_aux(root->left_, sum, cur_sum);
    if (root->right_ != nullptr)
        hasPathSum = hasPathSum || exists_root_to_leaf_path_sum_aux(root->right_, sum, cur_sum);

    return hasPathSum;
}

bool exists_root_to_leaf_path_sum(const pTreeNode& root, int sum)
{
    return exists_root_to_leaf_path_sum_aux(root, sum, 0);
}

int main()
{
    // Test case 1.
    pTreeNode tc1_root      (new BSTNode<int>(1));
    pTreeNode tc1_l         (new BSTNode<int>(5));
    pTreeNode tc1_r         (new BSTNode<int>(2));
    pTreeNode tc1_ll        (new BSTNode<int>(1));
    pTreeNode tc1_rl        (new BSTNode<int>(12));
    pTreeNode tc1_rr        (new BSTNode<int>(29));

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;
    tc1_l->left_            = tc1_ll;
    tc1_r->left_            = tc1_rl;
    tc1_r->right_           = tc1_rr;

    int tc1_target = 15;
    assert(exists_root_to_leaf_path_sum(tc1_root, tc1_target));

    // Test case 2.
    pTreeNode tc2_root      (new BSTNode<int>(104));
    pTreeNode tc2_l         (new BSTNode<int>(39));
    pTreeNode tc2_r         (new BSTNode<int>(31));
    pTreeNode tc2_ll        (new BSTNode<int>(32));
    pTreeNode tc2_lr        (new BSTNode<int>(1));
    pTreeNode tc2_rl        (new BSTNode<int>(9));
    pTreeNode tc2_rr        (new BSTNode<int>(10));

    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;
    tc2_l->left_            = tc2_ll;
    tc2_l->right_           = tc2_lr;
    tc2_r->left_            = tc2_rl;
    tc2_r->right_           = tc2_rr;

    int tc2_target = 175;
    assert(exists_root_to_leaf_path_sum(tc2_root, tc2_target));

    // Test case 3.
    pTreeNode tc3_root      (new BSTNode<int>(104));
    pTreeNode tc3_l         (new BSTNode<int>(39));
    pTreeNode tc3_r         (new BSTNode<int>(31));
    pTreeNode tc3_ll        (new BSTNode<int>(32));
    pTreeNode tc3_lr        (new BSTNode<int>(1));
    pTreeNode tc3_rl        (new BSTNode<int>(9));
    pTreeNode tc3_rr        (new BSTNode<int>(10));

    tc3_root->left_         = tc3_l;
    tc3_root->right_        = tc3_r;
    tc3_l->left_            = tc3_ll;
    tc3_l->right_           = tc3_lr;
    tc3_r->left_            = tc3_rl;
    tc3_r->right_           = tc3_rr;

    int tc3_target = 17;
    assert(!exists_root_to_leaf_path_sum(tc3_root, tc3_target));

    return 0;
}
