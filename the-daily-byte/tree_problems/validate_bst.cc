/**
 * The Daily Byte
 *
 * 04/07/2021
 *
 * Validate BST:
 * Given a binary tree, containing unique values, determine if it is a valid
 * BST
 * Note: the invariants of a BST (in our case) are all values to the left of
 * a given node are less than the current node's value, all values to the right
 * of a given node are greater than the current node's value, and both the left
 * and right subtrees of a given node must also be BSTs.
 */

#include <memory>
#include <cassert>
#include <limits>

#include "../data_structures/bst_node.h"

using std::make_shared;
using std::shared_ptr;
using std::numeric_limits;

using data_structures::BSTNode;
using pBSTNode = shared_ptr<BSTNode<int>>;

bool validate_bst_aux(const pBSTNode& root, int min_value, int max_value)
{
    if (root == nullptr) return true;
    if (root->data_ > min_value && root->data_ < max_value)
        return validate_bst_aux(root->left_, min_value, root->data_) &&
            validate_bst_aux(root->right_, root->data_, max_value);
    return false;
}

bool validate_bst(const pBSTNode& root)
{
    return validate_bst_aux(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main()
{
    // Test case 1.
    pBSTNode tc1_root       (new BSTNode<int>(1));
    pBSTNode tc1_l          (new BSTNode<int>(2));
    pBSTNode tc1_r          (new BSTNode<int>(3));
    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;

    assert(!validate_bst(tc1_root));

    // Test case 2.
    pBSTNode tc2_root       (new BSTNode<int>(2));
    pBSTNode tc2_l          (new BSTNode<int>(1));
    pBSTNode tc2_r          (new BSTNode<int>(3));
    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;

    assert(validate_bst(tc2_root));

    return 0;
}
