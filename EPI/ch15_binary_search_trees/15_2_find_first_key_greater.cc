/**
 * EPI Chapter 15 Binary Search Trees
 *
 * 15.2 Find a the first key greater than a given value in a BST
 *
 * Write a program that takes as input a BST and a value, and returns the first
 * key that would appear in an inorder traversal which is greater than the
 * input value.
 *
 * Hint: Perform binary search, keeping some additional state.
 */

#include <cstdio>
#include <memory>
#include <cassert>
#include <limits>

#include "../data_structures/binary_tree.hpp"

using std::make_shared;
using std::shared_ptr;
using std::numeric_limits;

using data_structures::BinaryTreeNode;

using pBSTNode = std::shared_ptr<BinaryTreeNode<int>>;

/**
 * Idea: Perform binary search. Record possible candidate whenever
 * out tree pointer's value is less than the value k.
 *
 * Time complexity: O(h)
 * Space complexity: O(1)
 */
pBSTNode FindFirstGreaterThanK(const pBSTNode root, int k)
{
    pBSTNode res = nullptr;
    pBSTNode candidate = nullptr;
    res = root;

    while (res != nullptr) {
        if (k < res->data_) {
            candidate = res;
            res = res->left_;                
        } else if (k >= res->data_) {
            res = res->right_;
        }
    }
    return candidate;
}

/**
 * Variant: Write a program that takes as input a BST and a value, and returns
 * the node whose key equals the input value and appears first in an inorder
 * traversal of the BST. Note that such BST can have duplicate values.
 *
 * Idea: If two keys are equal, prioritize leftest & deepest node.
 *
 * Time complexity: O(h)
 * Space complexity: O(1)
 */
pBSTNode FirstOccurrenceInBST(const pBSTNode& root, int k)
{
    pBSTNode candidate(nullptr);
    pBSTNode pIter(root);

    while (pIter != nullptr) {
        if (k == pIter->data_) {
            candidate = pIter;
            pIter = pIter->left_;
        } else if (k < pIter->data_) {
            pIter = pIter->left_;
        } else {
            pIter = pIter->right_;
        }
    }

    return candidate;
}


int main()
{
    pBSTNode tc1_A      (make_shared<BinaryTreeNode<int>>(19));
    pBSTNode tc1_B      (make_shared<BinaryTreeNode<int>>(7));
    pBSTNode tc1_C      (make_shared<BinaryTreeNode<int>>(3));
    pBSTNode tc1_D      (make_shared<BinaryTreeNode<int>>(2));
    pBSTNode tc1_E      (make_shared<BinaryTreeNode<int>>(5));
    pBSTNode tc1_F      (make_shared<BinaryTreeNode<int>>(11));
    pBSTNode tc1_G      (make_shared<BinaryTreeNode<int>>(17));
    pBSTNode tc1_H      (make_shared<BinaryTreeNode<int>>(13));
    pBSTNode tc1_I      (make_shared<BinaryTreeNode<int>>(43));
    pBSTNode tc1_J      (make_shared<BinaryTreeNode<int>>(23));
    pBSTNode tc1_K      (make_shared<BinaryTreeNode<int>>(37));
    pBSTNode tc1_L      (make_shared<BinaryTreeNode<int>>(29));
    pBSTNode tc1_N      (make_shared<BinaryTreeNode<int>>(41));
    pBSTNode tc1_M      (make_shared<BinaryTreeNode<int>>(32));
    pBSTNode tc1_O      (make_shared<BinaryTreeNode<int>>(47));
    pBSTNode tc1_P      (make_shared<BinaryTreeNode<int>>(53));

    tc1_A->left_        = tc1_B;
    tc1_A->right_       = tc1_I;
    tc1_B->left_        = tc1_C;
    tc1_B->right_       = tc1_F;
    tc1_C->left_        = tc1_D;
    tc1_C->right_       = tc1_E;
    tc1_F->right_       = tc1_G;
    tc1_G->left_        = tc1_H;

    tc1_I->left_        = tc1_J;
    tc1_I->right_       = tc1_O;
    tc1_J->right_       = tc1_K;
    tc1_K->left_        = tc1_L;
    tc1_K->right_       = tc1_N;
    tc1_L->right_       = tc1_M;

    tc1_O->right_       = tc1_P;

    assert(FindFirstGreaterThanK(tc1_A, 23)->data_ == 29);


    // Testing variants.
    pBSTNode tc_A       (make_shared<BinaryTreeNode<int>>(108));
    pBSTNode tc_B       (make_shared<BinaryTreeNode<int>>(108));
    pBSTNode tc_C       (make_shared<BinaryTreeNode<int>>(-10));
    pBSTNode tc_D       (make_shared<BinaryTreeNode<int>>(-14));
    pBSTNode tc_E       (make_shared<BinaryTreeNode<int>>(2));
    pBSTNode tc_F       (make_shared<BinaryTreeNode<int>>(108));
    pBSTNode tc_G       (make_shared<BinaryTreeNode<int>>(285));
    pBSTNode tc_H       (make_shared<BinaryTreeNode<int>>(243));
    pBSTNode tc_I       (make_shared<BinaryTreeNode<int>>(285));
    pBSTNode tc_J       (make_shared<BinaryTreeNode<int>>(401));

    tc_A->left_         = tc_B;
    tc_A->right_        = tc_G;

    tc_B->left_         = tc_C;
    tc_B->right_        = tc_F;
    
    tc_C->left_         = tc_D;
    tc_C->right_        = tc_E;

    tc_G->left_         = tc_H;
    tc_G->right_        = tc_I;

    tc_I->right_        = tc_J;

    assert(FirstOccurrenceInBST(tc_A, 108) == tc_B);
    assert(FirstOccurrenceInBST(tc_A, 285) == tc_G);
    assert(FirstOccurrenceInBST(tc_A, 143) == nullptr);

    return 0;
}
