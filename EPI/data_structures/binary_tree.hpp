#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_

#include <memory>

using std::unique_ptr;
using std::weak_ptr;
using std::shared_ptr;

namespace data_structures
{

template <typename T>
struct BinaryTreeNode
{
    BinaryTreeNode(T data) : data_(data), left_(nullptr), right_(nullptr), parent_(nullptr) {}
    BinaryTreeNode(T data, 
            shared_ptr<BinaryTreeNode<T>> l,
            shared_ptr<BinaryTreeNode<T>> r)
        : data_(data), left_(l), right_(r), parent_(nullptr) {}

    BinaryTreeNode(T data,
            shared_ptr<BinaryTreeNode<T>> l,
            shared_ptr<BinaryTreeNode<T>> r,
            shared_ptr<BinaryTreeNode<T>> p)
        : data_(data), left_(l), right_(r), parent_(p) {}

    T data_;
    shared_ptr<BinaryTreeNode<T>> left_, right_, parent_;
};

}
#endif

