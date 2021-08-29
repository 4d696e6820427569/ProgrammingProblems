/**
 * The Daily Byte
 *
 * Given an N-ary tree, returns its maximum depth.
 *
 * Note: An N-ary tree is a tree in which any node may have at most N children.
 */

#include <vector>
#include <cassert>
#include "../data_structures/nary_tree.h"

using data_structures::NTreeNode;

using pNTreeNode = shared_ptr<NTreeNode<int>>;

void DivingDeepHelper(const pNTreeNode& root, int& max_depth, int cur_depth)
{
    if (root != nullptr) {
        max_depth = max_depth > cur_depth ? max_depth : cur_depth;
        for(const auto& child : root->children_) {
            DivingDeepHelper(child, max_depth, cur_depth + 1);
        }
    }
}

int DivingDeep(const pNTreeNode& root)
{
    int max_depth = 0;
    DivingDeepHelper(root, max_depth, 1);
    return max_depth;
}

int main()
{
    pNTreeNode tc1_root      (make_shared<NTreeNode<int>>(4));
    pNTreeNode tc1_21        (make_shared<NTreeNode<int>>(3));
    pNTreeNode tc1_22        (make_shared<NTreeNode<int>>(9));
    pNTreeNode tc1_23        (make_shared<NTreeNode<int>>(2));
    pNTreeNode tc1_31        (make_shared<NTreeNode<int>>(7));
    pNTreeNode tc1_32        (make_shared<NTreeNode<int>>(2));
    tc1_root->children_.emplace_back(tc1_21);
    tc1_root->children_.emplace_back(tc1_22);
    tc1_root->children_.emplace_back(tc1_23);
    tc1_21->children_.emplace_back(tc1_31);
    tc1_23->children_.emplace_back(tc1_32);

    assert(DivingDeep(tc1_root) == 3);


    return 0;
}
