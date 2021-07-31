/**
 * EPI Chapter 13 Hash Tables
 *
 * 13.4 Compute the LCA, optimizing for close ancestors.
 *
 * Problem 10.4 is concerned with computing the LCA in a binary tree with
 * parent pointers in time proportional to the height of the tree. The
 * algorithm presented entails traversing all the way to the root even if
 * the nodes whose LCA is being computed are very close to their LCA.
 *
 * Design an algorithm for computing the LCA of 2 nodes in a binary tree. The
 * algorithm's time complexity should depend only on the distance from the
 * nodes to the LCA.
 *
 * Hint: Focus on the extreme case described.
 */

#include <unordered_map>
#include <unordered_set>
#include <cassert>

#include "../data_structures/binary_tree.hpp"

using std::unordered_set;
using std::unordered_map;
using std::make_shared;

using data_structures::BinaryTreeNode;

using pBTreeNode = shared_ptr<BinaryTreeNode<int>>;

/**
 * Idea: Record the visited nodes when we traverse up.
 *
 * Time complexity: O(d1 + d2) where d1 and d2 are the distance
 *  from the the nodes to the LCA.
 * Space complexity: O(d1 + d2)
 */
pBTreeNode GetLCA(const pBTreeNode& node1, const pBTreeNode& node2)
{
    pBTreeNode pTmp1 = node1;
    pBTreeNode pTmp2 = node2;
    unordered_set<pBTreeNode> nodes;

    while (pTmp1->parent_ != nullptr && pTmp2->parent_ != nullptr) {
        if (nodes.find(pTmp1) == nodes.end()) {
            nodes.emplace(pTmp1);
        } else {
            return pTmp1;
        }

        if (nodes.find(pTmp2) == nodes.end()) {
            nodes.emplace(pTmp2);
        } else {
            return pTmp2;
        }

        pTmp1 = pTmp1->parent_;
        pTmp2 = pTmp2->parent_;
    }

    while (pTmp1 != nullptr) {
        if (nodes.find(pTmp1) == nodes.end()) {
            nodes.emplace(pTmp1);
        } else {
            return pTmp1;
        }

        pTmp1 = pTmp1->parent_;
    }

    while (pTmp2 != nullptr) {
        if (nodes.find(pTmp2) == nodes.end()) {
            nodes.emplace(pTmp2);
        } else {
            return pTmp2;
        }

        pTmp2 = pTmp2->parent_;
    }

    // Impossible to reach here.
    return nullptr;
}

int main()
{
    shared_ptr<BinaryTreeNode<int>> tc1_root          (make_shared<BinaryTreeNode<int>>('A'));

    tc1_root->left_                              =     make_shared<BinaryTreeNode<int>>('B');
    tc1_root->left_->parent_ = tc1_root;

    tc1_root->right_                             =     make_shared<BinaryTreeNode<int>>('K');
    tc1_root->right_->parent_ = tc1_root;

    tc1_root->left_->left_                       =     make_shared<BinaryTreeNode<int>>('C');
    tc1_root->left_->left_->parent_ = tc1_root->left_;

    tc1_root->left_->right_                      =     make_shared<BinaryTreeNode<int>>('H');
    tc1_root->left_->right_->parent_ = tc1_root->left_; 

    tc1_root->right_->left_                      =     make_shared<BinaryTreeNode<int>>('L');
    tc1_root->right_->left_->parent_ = tc1_root->right_;

    tc1_root->right_->right_                     =     make_shared<BinaryTreeNode<int>>('O');
    tc1_root->right_->right_->parent_ = tc1_root->right_;

    tc1_root->left_->left_->left_                =     make_shared<BinaryTreeNode<int>>('D');
    tc1_root->left_->left_->left_->parent_ = tc1_root->left_->left_;

    tc1_root->left_->left_->right_               =     make_shared<BinaryTreeNode<int>>('G');
    tc1_root->left_->left_->right_->parent_ = tc1_root->left_->left_;

    tc1_root->left_->right_->left_               =     make_shared<BinaryTreeNode<int>>('I');
    tc1_root->left_->right_->left_->parent_ = tc1_root->left_->right_;

    tc1_root->left_->right_->right_              =     make_shared<BinaryTreeNode<int>>('J');
    tc1_root->left_->right_->right_->parent_ = tc1_root->left_->right_;

    tc1_root->right_->left_->left_               =     make_shared<BinaryTreeNode<int>>('M');
    tc1_root->right_->left_->left_->parent_ = tc1_root->right_->left_;

    tc1_root->right_->left_->right_              =     make_shared<BinaryTreeNode<int>>('N');
    tc1_root->right_->left_->right_->parent_ = tc1_root->right_->left_;

    tc1_root->left_->left_->left_->left_         =     make_shared<BinaryTreeNode<int>>('E');
    tc1_root->left_->left_->left_->left_->parent_ = tc1_root->left_->left_->left_;

    tc1_root->left_->left_->left_->right_        =     make_shared<BinaryTreeNode<int>>('F');
    tc1_root->left_->left_->left_->right_->parent_ = tc1_root->left_->left_->left_;

    // I and J. Should return B.
    assert(GetLCA(tc1_root->left_->left_->left_->left_,
                tc1_root->left_->right_->right_) == tc1_root->left_);
    return 0;
}
