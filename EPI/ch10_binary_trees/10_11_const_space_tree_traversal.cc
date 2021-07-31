/**
 * EPI - Chapter 10 Binary Trees
 *
 * 07/19/2021
 * Implement an inorder traversal with O(1) space
 *
 * The direct implementation of an inorder traversal using recursion has O(h)
 * space complexity, where h is the height of the tree. Recursion can be
 * removed with an explicit stack, but the space complexity remains O(h).
 *
 * Write a nonrecursive program for computing the inorder traversal sequence
 * for a binary tree. Assume nodes have parent fields.
 *
 * Hint: How can you tell where a node is a left child or right child of its
 * parent?
 */

#include <cassert>
#include <vector>
#include <memory>

#include "../data_structures/binary_tree.hpp"

using std::make_shared;
using std::shared_ptr;
using std::vector;

using data_structures::BinaryTreeNode;
using pTreeNode = shared_ptr<BinaryTreeNode<int>>;

void InorderTraversal(const pTreeNode& tree, vector<int> inorder)
{
    if (tree != nullptr) {
        InorderTraversal(tree->left_, inorder);
        inorder.emplace_back(tree->data_);
        InorderTraversal(tree->right_, inorder);
    }
}

void InorderTraversalConstSpace(const pTreeNode& tree, vector<int> inorder)
{
    pTreeNode pTmp = tree;
    pTreeNode pPrev = nullptr;
    
    while (pTmp != nullptr) {
        pTreeNode next = nullptr;
        if (pTmp->parent_ == pPrev) {
            // Came down to pTmp from pPrev.
            if (pTmp->left_ != nullptr) {
                // Keep going left till we can't.
                next = pTmp->left_;
            } else {
                inorder.emplace_back(pTmp->data_);

                // Check if right is nullptr. If it's nullptr, we go up.
                // Otherwise, set next node to pTmp's right child.
                next = pTmp->right_ == nullptr ? pTmp->parent_ : pTmp->right_;
            }
        } else if (pTmp->left_ == pPrev) {
            // Come up from a left subtree.
            // Check if right is nullptr. If it is, go up.
            inorder.emplace_back(pTmp->data_);
            next = pTmp->right_ == nullptr ? pTmp->parent_ : pTmp->right_;
        } else {
            // Done traversing all tree.
            next = pTmp->parent_;
        }

        pPrev = pTmp;
        pTmp = next;
    }
}

int main()
{
    pTreeNode tc1_root          (make_shared<BinaryTreeNode<int>>('H'));
    pTreeNode tc1_l             (make_shared<BinaryTreeNode<int>>('B'));
    pTreeNode tc1_r             (make_shared<BinaryTreeNode<int>>('C'));
    pTreeNode tc1_ll            (make_shared<BinaryTreeNode<int>>('F'));
    pTreeNode tc1_lr            (make_shared<BinaryTreeNode<int>>('E'));
    pTreeNode tc1_lrl           (make_shared<BinaryTreeNode<int>>('A'));
    pTreeNode tc1_rr            (make_shared<BinaryTreeNode<int>>('D'));
    pTreeNode tc1_rrr           (make_shared<BinaryTreeNode<int>>('G'));
    pTreeNode tc1_rrrl          (make_shared<BinaryTreeNode<int>>('I'));

    tc1_root->parent_           = nullptr;
    tc1_root->left_             = tc1_l;
    tc1_l->parent_              = tc1_root;
    tc1_root->right_            = tc1_r;
    tc1_r->parent_              = tc1_root;

    tc1_l->left_                = tc1_ll;
    tc1_ll->parent_             = tc1_l;
    tc1_l->right_               = tc1_lr;
    tc1_lr->parent_             = tc1_l;
    tc1_lr->left_               = tc1_lrl;
    tc1_lrl->parent_            = tc1_lr;
    tc1_r->right_               = tc1_rr;
    tc1_rr->parent_             = tc1_r;
    tc1_rr->right_              = tc1_rrr;
    tc1_rrr->parent_            = tc1_rr;
    tc1_rrr->left_              = tc1_rrrl;
    tc1_rrrl->parent_           = tc1_rrr;

    vector<int> tc1_inorder;
    vector<int> tc1_res;
    InorderTraversal(tc1_root, tc1_inorder);
    InorderTraversalConstSpace(tc1_root, tc1_res);
    assert(tc1_res == tc1_inorder);
    return 0;
}
