/**
 * EPI Chapter 10 Binary Trees
 *
 * A binary tree is symmetric if you can draw a vertical line through the root
 * and then left subtree is the mirror image of the right subtree.
 *
 * Write a program that checks whether a binary tree is symmetric.
 *
 * Hint: The definition of symmetry is recursive.
 */


#include <cstdio>
#include <memory>
#include <cassert>

#include "../data_structures/binary_tree.hpp"

using std::shared_ptr;
using std::make_shared;
using std::shared_ptr;
using std::make_shared;

using data_structures::BinaryTreeNode;

bool isSymmetric(const shared_ptr<BinaryTreeNode<int>>& tree)
{
    if (tree == nullptr) return true;

    // What are the cases when it's NOT symmetric?
    // 1. left is null and right is not null
    // 2. left is not null and right is null
    // 3. left and right are not null but not equal.
    // 4. Left is asymmetric and right is symmetric.
    // 5. Left is symmetric and right is aymmetric.
    //
    //
    // What are the cases when they're symmetric?
    // 1. Single node.
    // 2. Same node values but has inverse structure.
    // 3. Left and right have to be symmetric through root.
    // 4. Left and right have to be both asymmetric through root.
}

int main()
{
    return 0;
}
