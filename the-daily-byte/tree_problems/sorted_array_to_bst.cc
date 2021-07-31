/**
 * The Daily Byte 06/19/2021
 * Sorted Array to BST
 *
 * Given an array of numbers sorted in ascending order, return a
 * height balanced binary search tree using every number from the array.
 *
 * Note: Height-balanced meaning that the level of any node's 2 subtrees
 * should not differ by more than one.
 */

#include <cstdio>
#include <vector>
#include <memory>
#include <cassert>

using std::vector;
using std::shared_ptr;
using std::make_shared;

struct BSTNode
{
    int data_;
    shared_ptr<BSTNode> left_;
    shared_ptr<BSTNode> right_;
};

struct RedBlackTree
{
    RedBlackTree() = default;

};

bool bst_equals(shared_ptr<BSTNode> &tree1, shared_ptr<BSTNode> &tree2)
{
    return false;
}

shared_ptr<BSTNode> sorted_array_to_bst(const vector<int>& v)
{
    shared_ptr<BSTNode> root;
    return root;
}

int main()
{
    // Test case 1.
    vector<int> tc1{1, 2, 3};
    shared_ptr<BSTNode> tc1_root(new BSTNode);
    shared_ptr<BSTNode> tc1_l(new BSTNode);
    shared_ptr<BSTNode> tc1_r(new BSTNode);

    tc1_root->data_ = 2;
    tc1_root->left_ = tc1_l;
    tc1_root->right_ = tc1_r;

    tc1_l->data_ = 1;
    tc1_r->data_ = 3;
    
    shared_ptr<BSTNode> rbt1 = sorted_array_to_bst(tc1);
    assert(bst_equals(rbt1, tc1_root));

    // Test case 2.
    vector<int> tc2{1, 2, 3, 4, 5, 6};
    shared_ptr<BSTNode> tc2_root(new BSTNode);
    shared_ptr<BSTNode> tc2_l(new BSTNode);
    shared_ptr<BSTNode> tc2_r(new BSTNode);
    shared_ptr<BSTNode> tc2_lr(new BSTNode);
    shared_ptr<BSTNode> tc2_rl(new BSTNode);
    shared_ptr<BSTNode> tc2_rr(new BSTNode);

    tc2_root->data_ = 3;
    tc2_root->left_ = tc2_l;
    tc2_root->right_ = tc2_r;

    tc2_l->data_ = 2;
    tc2_l->right_ = tc2_lr;
    tc2_lr->data_ = 1;

    tc2_r->data_ = 5;
    tc2_r->left_ = tc2_rl;
    tc2_r->right_ = tc2_rr;
    tc2_rl->data_ = 4;
    tc2_rr->data_ = 6;

    shared_ptr<BSTNode> rbt2 = sorted_array_to_bst(tc2);
    assert(bst_equals(rbt2, tc2_root));

    return 0;
}
