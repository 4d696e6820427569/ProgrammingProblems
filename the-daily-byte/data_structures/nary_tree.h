#ifndef NARY_TREE_H_
#define NARY_TREE_H_

#include <memory>
#include <vector>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::vector;

namespace data_structures
{
template<typename T>
struct NTreeNode
{
    NTreeNode() = default;
    NTreeNode(NTreeNode<T>&) = delete;
    ~NTreeNode() = default;
    NTreeNode<T>& operator=(NTreeNode<T>&) = delete;

    T data_;
    vector<shared_ptr<NTreeNode<T>>> children_;
};

template<>
struct NTreeNode<int>
{   
    NTreeNode() = default;
    NTreeNode(int data) : data_(data) {};

    int data_;
    vector<shared_ptr<NTreeNode<int>>> children_;
};
};

#endif
