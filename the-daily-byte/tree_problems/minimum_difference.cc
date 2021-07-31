/**
 * The Daily Byte 06/21/2021
 *
 * Given a BST, return the minimum difference between any 2 nodes in the tree
 */

/**
 * Claim: The minimum difference between any two nodes in the BST is the minimum
 * of the differences between a node and its successor.
 *
 * Why? Because we're dealing with BST, a successor of a node is defined as the
 * node preceed it when we traverse the BST in order.
 *
 * So, we can do an inorder tree traversal, and check for the difference between
 * each node. Since the nodes are sorted by key, we can easily find the smallest
 * difference.
 */

#include "../data_structures/bst_node.h"

#include <cassert>
#include <memory>
#include <vector>
#include <limits>

using data_structures::BSTNode;
using std::make_shared;
using std::vector;

using pBSTNode = shared_ptr<BSTNode<int>>;

/**
 * Time complexity will be O(n).
 * Space complexity will be O(n).
 */

void inorder_bst_traversal(pBSTNode root, vector<int>& inorder, int& min_difference)
{
    if (root == nullptr) return;
    inorder_bst_traversal(root->left_, inorder, min_difference);
    inorder.emplace_back(root->data_);
    if (inorder.size() >= 2 && 
            min_difference > inorder[inorder.size() - 1] - inorder[inorder.size() - 2])
        min_difference = inorder[inorder.size() - 1] - inorder[inorder.size() - 2];

    inorder_bst_traversal(root->right_, inorder, min_difference);
}

int minimum_difference(pBSTNode root)
{
    vector<int> inorder;
    int min_difference = std::numeric_limits<int>::max();
    inorder_bst_traversal(root, inorder, min_difference);
    return min_difference;
}


int main()
{
    // Test case 1
    pBSTNode tc1_root(new BSTNode<int>);
    pBSTNode tc1_l(new BSTNode<int>);
    pBSTNode tc1_r(new BSTNode<int>);

    tc1_root->left_ = tc1_l;
    tc1_root->right_ = tc1_r;

    tc1_root->data_ = 2;
    tc1_l->data_ = 1;
    tc1_r->data_ = 3;
    
    assert(minimum_difference(tc1_root) == 1);

    // Test case 2
    pBSTNode tc2_root (new BSTNode<int>);
    pBSTNode tc2_l    (new BSTNode<int>);
    pBSTNode tc2_r    (new BSTNode<int>);
    pBSTNode tc2_ll   (new BSTNode<int>);
    pBSTNode tc2_rl   (new BSTNode<int>);
    pBSTNode tc2_rr   (new BSTNode<int>);

    tc2_root->data_ = 29;
    tc2_root->left_ = tc2_l;
    tc2_root->right_ = tc2_r;

    tc2_l->data_ = 17;
    tc2_l->left_ = tc2_ll;

    tc2_ll->data_ = 1;

    tc2_r->data_ = 50;
    tc2_r->left_ = tc2_rl;
    tc2_r->right_ = tc2_rr;

    tc2_rl->data_ = 42;
    tc2_rr->data_ = 59;

    assert(minimum_difference(tc2_root) == 8);

    // Test case 3
    pBSTNode tc3_root (new BSTNode<int>);
    pBSTNode tc3_r    (new BSTNode<int>);
    
    tc3_root->data_ = 2;
    tc3_root->right_ = tc3_r;

    tc3_r->data_ = 100;

    assert(minimum_difference(tc3_root) == 98);

    return 0;
}
