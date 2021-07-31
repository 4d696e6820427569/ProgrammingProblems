/**
 * The Daily Byte 06/20/2021
 *
 * Given 2 binary trees, return whether or not the 2 trees are identical.
 *
 * Note: identical meaning they exhibit the same structure and the same
 * values at each node.
 */

#include "../data_structures/bst_node.h"

#include <memory>
#include <cassert>
#include <stack>

#define ASSERT_RECURSIVE_SOL 1
#define ASSERT_ITERATIVE_SOL 1

using std::shared_ptr;
using std::make_shared;
using std::stack;
using data_structures::BSTNode;

using pBSTNode = shared_ptr<BSTNode<int>>;

/**
 * Time complexity: O(n)
 * Space complexity: O(lgn) due to recursion.
 */
bool is_identical_recursive(pBSTNode& tree1, pBSTNode& tree2)
{
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    } else if (tree1 != nullptr && tree2 != nullptr) {
        if (tree1->data_ != tree2->data_) {
            return false;
        }
        return is_identical_recursive(tree1->left_, tree2->left_) &&
                is_identical_recursive(tree1->right_, tree1->right_);

    } else {
        return false;
    }
}

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
bool is_identical_iterative(pBSTNode& tree1, pBSTNode& tree2)
{
    pBSTNode pTree1 = nullptr;
    pBSTNode pTree2 = nullptr;

    stack<pBSTNode> tree1_stack;
    stack<pBSTNode> tree2_stack;

    tree1_stack.emplace(tree1);
    tree2_stack.emplace(tree2);

    while (!tree1_stack.empty() && !tree2_stack.empty()) {
        pTree1 = tree1_stack.top();
        pTree2 = tree2_stack.top();
        tree1_stack.pop();
        tree2_stack.pop();

        if (pTree1->data_ != pTree2->data_) return false;
        if (pTree1->left_ != nullptr && pTree2->left_ != nullptr) {
            tree1_stack.emplace(pTree1->left_);
            tree2_stack.emplace(pTree2->left_);
        } else if (pTree1->left_ == nullptr && pTree2->left_ == nullptr) {

        } else {
            return false;
        }

        if (pTree1->right_ != nullptr && pTree2->right_ != nullptr) {
            tree1_stack.emplace(pTree1->right_);
            tree2_stack.emplace(pTree2->right_);
        } else if (pTree1->right_ == nullptr && pTree2->right_ == nullptr) {

        } else {
            return false;
        }
    }

    if (!tree1_stack.empty() || !tree2_stack.empty()) return false;

    return true;
}

int main()
{
    // Test case 1.
    pBSTNode tc1_1_root(new BSTNode<int>);
    pBSTNode tc1_1_l(new BSTNode<int>);
    pBSTNode tc1_1_r(new BSTNode<int>);

    tc1_1_root->data_ = 2;
    tc1_1_root->left_ = tc1_1_l;
    tc1_1_root->right_ = tc1_1_r;
    tc1_1_l->parent_ = tc1_1_root;
    tc1_1_r->parent_ = tc1_1_root;

    tc1_1_l->data_ = 1;
    tc1_1_r->data_ = 3;

    pBSTNode tc1_2_root(new BSTNode<int>);
    pBSTNode tc1_2_l(new BSTNode<int>);
    pBSTNode tc1_2_r(new BSTNode<int>);

    tc1_2_root->data_ = 2;
    tc1_2_root->left_ = tc1_2_l;
    tc1_2_root->right_ = tc1_2_r;
    tc1_2_l->parent_ = tc1_2_root;
    tc1_2_r->parent_ = tc1_2_root;

    tc1_2_l->data_ = 1;
    tc1_2_r->data_ = 3;

    
    // Test case 2.
    pBSTNode tc2_1_root(new BSTNode<int>);
    pBSTNode tc2_1_r(new BSTNode<int>);
    pBSTNode tc2_1_rr(new BSTNode<int>);

    tc2_1_root->data_ = 1;
    tc2_1_root->right_ = tc1_1_r;
    tc2_1_r->right_ = tc2_1_rr;

    tc2_1_r->data_ = 9;
    tc2_1_rr->data_ = 18;
    tc2_1_r->parent_ = tc2_1_root;
    tc2_1_rr->parent_ = tc2_1_r;

    pBSTNode tc2_2_root(new BSTNode<int>);
    pBSTNode tc2_2_l(new BSTNode<int>);
    pBSTNode tc2_2_lr(new BSTNode<int>);

    tc2_2_root->data_ = 1;
    tc2_2_root->left_ = tc2_2_l;
    tc2_2_l->right_ = tc2_2_lr;

    tc2_2_l->data_ = 9;
    tc2_2_l->parent_ = tc2_2_root;
    tc2_2_lr->data_ = 18;
    tc2_2_lr->parent_ = tc2_2_l;


    // Test case 3.
    pBSTNode tc3_1_root(new BSTNode<int>) ;
    pBSTNode tc3_1_l   (new BSTNode<int>) ;
    pBSTNode tc3_1_r   (new BSTNode<int>) ;

    tc3_1_root->data_ = 2 ;
    tc3_1_l   ->data_ = 3 ;
    tc3_1_r   ->data_ = 1 ;

    tc3_1_root->left_ = tc3_1_l;
    tc3_1_root->right_ = tc3_1_r;
    tc3_1_l->parent_ = tc3_1_root;
    tc3_1_r->parent_ = tc3_1_root;

    pBSTNode tc3_2_root(new BSTNode<int>) ;
    pBSTNode tc3_2_l   (new BSTNode<int>) ;
    pBSTNode tc3_2_r   (new BSTNode<int>) ;

    tc3_2_root->data_ = 2 ;
    tc3_2_l   ->data_ = 1 ;
    tc3_2_r   ->data_ = 3 ;

    tc3_2_root->left_ = tc3_2_l;
    tc3_2_root->right_ = tc3_2_r;
    tc3_2_l->parent_ = tc3_2_root;
    tc3_2_r->parent_ = tc3_2_root;


    if (ASSERT_RECURSIVE_SOL) {
        assert(is_identical_recursive(tc1_1_root, tc1_2_root));
        assert(!is_identical_recursive(tc2_1_root, tc2_2_root));
        assert(!is_identical_recursive(tc3_1_root, tc3_2_root));
    }
    
    if (ASSERT_ITERATIVE_SOL) {
        assert(is_identical_iterative(tc1_1_root, tc1_2_root));
        assert(!is_identical_iterative(tc2_1_root, tc2_2_root));
        assert(!is_identical_iterative(tc3_1_root, tc3_2_root));
    }
    return 0;
}
