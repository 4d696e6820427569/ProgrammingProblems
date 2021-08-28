#ifndef BST_NODE_H_
#define BST_NODE_H_

#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;

namespace data_structures
{
template <typename T>
struct BSTNode
{
    BSTNode() = default;
    BSTNode(BSTNode<T>&) = delete;
    ~BSTNode() = default;
    BSTNode<T>& operator=(BSTNode<T>&) = delete;

    T data_;
    shared_ptr<BSTNode<T>> left_, right_, parent_;
};

template<>
struct BSTNode<int>
{
    BSTNode() {}
    BSTNode(int n) : data_(n) {}
    BSTNode(int n, shared_ptr<BSTNode<int>> left, shared_ptr<BSTNode<int>> right)
        : data_(n), left_(left), right_(right) {};
    int data_;
    shared_ptr<BSTNode<int>> left_, right_, parent_;
};

bool bst_equals(shared_ptr<BSTNode<int>>& tree1, shared_ptr<BSTNode<int>>& tree2)
{
    if (tree1 == nullptr && tree2 == nullptr) { return true; }
    else if (tree1 != nullptr && tree2 != nullptr) {
        return tree1->data_ == tree2->data_ &&
            bst_equals(tree1->left_, tree2->left_) &&
            bst_equals(tree1->right_, tree2->right_);
    } else {
        return false;
    }
};

shared_ptr<BSTNode<int>> find(shared_ptr<BSTNode<int>>& tree, int value)
{
    if (tree == nullptr) {
        return nullptr;
    } else {
        if (value == tree->data_) {
            return tree;
        } else if (value < tree->data_) {
            return find(tree->left_, value);
        } else {
            return find(tree->right_, value);
        }
    }
};

void insert(shared_ptr<BSTNode<int>> tree, int value)
{
};


}

#endif
