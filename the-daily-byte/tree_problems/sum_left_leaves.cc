/**
 * The Daily Byte
 * 07/07/2021
 *
 * Given a binary tree, return the sum of all left leaves of the tree.
 *
 * Sum Left Leaves
 */

#include <memory>
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <utility>

#include "../data_structures/bst_node.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

using data_structures::BSTNode;

using pTreeNode = shared_ptr<BSTNode<int>>;

/**
 * We will have a recursive procedure, traversing the entire tree.
 * The procedure will have 2 features.
 * 1. Detecting leaf nodes.
 * 2. Detecting left nodes. Accomplished by passing a boolean as an argument
 * to the procedure.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int SumLeftLeavesAux(const pTreeNode& root, bool is_left, int cur_sum)
{
    if (root == nullptr) return cur_sum;

    cur_sum = SumLeftLeavesAux(root->left_, true, cur_sum);
    cur_sum = SumLeftLeavesAux(root->right_, false, cur_sum);
    if (is_left && root->left_ == nullptr && root->right_ == nullptr)
        cur_sum += root->data_;
    return cur_sum;
}

int SumLeftLeaves(const pTreeNode& root)
{
    return SumLeftLeavesAux(root, false, 0);
}

int main()
{
    // Test case 1.
    pTreeNode tc1_root      (new BSTNode<int>(5));
    pTreeNode tc1_l         (new BSTNode<int>(2));
    pTreeNode tc1_r         (new BSTNode<int>(12));
    pTreeNode tc1_rl        (new BSTNode<int>(3));
    pTreeNode tc1_rr        (new BSTNode<int>(8));

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;
    tc1_r->left_            = tc1_rl;
    tc1_r->right_           = tc1_rr;

    int tc1_res = 5;
    assert(SumLeftLeaves(tc1_root) == tc1_res);

    // Test case 2.
    pTreeNode tc2_root      (new BSTNode<int>(2));
    pTreeNode tc2_l         (new BSTNode<int>(4));
    pTreeNode tc2_r         (new BSTNode<int>(2));
    pTreeNode tc2_ll        (new BSTNode<int>(3));
    pTreeNode tc2_lr        (new BSTNode<int>(9));

    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;
    tc2_l->right_           = tc2_lr;
    tc2_l->left_            = tc2_ll;

    int tc2_res = 3;
    assert(SumLeftLeaves(tc2_root) == tc2_res);

    return 0;
}
