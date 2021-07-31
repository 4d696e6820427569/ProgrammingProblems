/**
 * The Daily Byte
 * 07/01/2021
 *
 * Given a binary tree, return its maximum depth.
 *
 * Note: the maximum depth is defined as the number of nodes along the longest
 * path from root node to leaf node.
 */

#include <memory>
#include <cassert>
#include <algorithm>
#include "../data_structures/bst_node.h"

using std::shared_ptr;
using std::make_shared;

using data_structures::BSTNode;
using pBSTNode = shared_ptr<BSTNode<int>>;

int max_depth_aux(pBSTNode root, int max_depth)
{
    if (root == nullptr) return max_depth;
    return std::max(max_depth_aux(root->left_, max_depth),
            max_depth_aux(root->right_, max_depth)) + 1;
}

int max_depth(pBSTNode root)
{
    return max_depth_aux(root, 0);
}

int main()
{
    // Test case 1.
    pBSTNode tc1_root       (new BSTNode<int>);
    pBSTNode tc1_l          (new BSTNode<int>);
    pBSTNode tc1_r          (new BSTNode<int>);

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;

    tc1_root->data_         = 9;
    tc1_l->data_            = 1;
    tc1_r->data_            = 2;
    
    int tc1_res = 2;
    assert(max_depth(tc1_root) == tc1_res);

    // Test case 2.
    pBSTNode tc2_root       (new BSTNode<int>);
    pBSTNode tc2_l          (new BSTNode<int>);
    pBSTNode tc2_r          (new BSTNode<int>);
    pBSTNode tc2_rl         (new BSTNode<int>);
    pBSTNode tc2_rr         (new BSTNode<int>);

    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;

    tc2_r->left_            = tc2_rl;
    tc2_r->right_           = tc2_rr;

    int tc2_res = 3;
    assert(max_depth(tc2_root) == tc2_res);

    return 0;
}
