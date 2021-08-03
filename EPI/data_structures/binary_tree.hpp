#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_

#include <memory>
#include <vector>
#include <stdexcept>
#include <utility>

using std::unique_ptr;
using std::weak_ptr;
using std::shared_ptr;
using std::pair;
using std::make_pair;
using std::make_shared;
using std::vector;

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

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree()
        : root_(nullptr)
        , n_(0)
    {

    }

    BinarySearchTree(const BinarySearchTree& bst) = delete;
    ~BinarySearchTree() = default;
    BinarySearchTree& operator=(const BinarySearchTree& bst) = delete;

    pair<shared_ptr<BinaryTreeNode<T>>, bool>
    Insert(T data)
    {
        if (Empty()) {
            root_ = make_shared<BinaryTreeNode<T>>(data);
            n_++;
            return make_pair(root_, true);
        } else {
            // Find a place to insert.
            shared_ptr<BinaryTreeNode<T>> pParent(nullptr);
            shared_ptr<BinaryTreeNode<T>> pTmp(root_);

            while (pTmp != nullptr) {
                pParent = pTmp;
                if (data < pTmp->data_) {
                    pTmp = pTmp->left_;
                } else if (data > pTmp->data_) {
                    pTmp = pTmp->right_;
                } else {
                    // Duplicate keys.
                    return make_pair(pTmp, false);
                }
            }

            shared_ptr<BinaryTreeNode<T>> new_node(make_shared<BinaryTreeNode<T>>(data));
            new_node->parent_ = pParent;
            if (pParent->data_ < data) {
                pParent->right_ = new_node;
            } else if (pParent->data_ > data) {
                pParent->left_ = new_node;
            }
            n_++;
            return make_pair(new_node, true);
        }
        return make_pair(nullptr, false);
    }

    bool
    Delete(T data)
    {
        shared_ptr<BinaryTreeNode<T>> pTmp(root_);
        shared_ptr<BinaryTreeNode<T>> pParent(nullptr);

        while (pTmp != nullptr && pTmp->data_ != data) {
            pParent = pTmp;
            if (data < pTmp->data_) {
                pTmp = pTmp->left_;
            } else {
                pTmp = pTmp->right_;
            }
        }

        // Can't find that node.
        if (pTmp == nullptr) return false;

        shared_ptr<BinaryTreeNode<T>> found_node = pTmp;

        if (found_node->right_ != nullptr) {
            // Find the minimum on the right subtree. i.e. the successor.
            shared_ptr<BinaryTreeNode<T>> successor = found_node->right_;
            shared_ptr<BinaryTreeNode<T>> successor_parent = found_node;

            while (successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left_;
            }

            // Set the found node's data to its successor's data.
            found_node->data_ = successor->data_;

            // Moves links to erase the successor.
            if (successor_parent->left_ == successor) {
                successor_parent->left_ = successor->right_;
            } else {
                successor_parent->right_ = successor->right_;
            }

        } else {
            // Update root_ link if needed.
            if (root_ == found_node) {
                root_ = found_node->left_;
            } else {
                if (pParent->left_ == found_node) {
                    pParent->left_ = found_node->left_;
                } else {
                    pParent->right_ = found_node->left_;
                }
            }
        }
        return true;
    }

    shared_ptr<BinaryTreeNode<T>>
    FindMin() const
    {
        return FindMin(root_);
    }

    shared_ptr<BinaryTreeNode<T>>
    FindMax() const
    {
        return FindMax(root_);
    }

    shared_ptr<BinaryTreeNode<T>>
    FindSuccessor(T data)
    {
        shared_ptr<BinaryTreeNode<T>> key_node = Find(data);
        shared_ptr<BinaryTreeNode<T>> successor(nullptr);
        if (key_node != nullptr) {
            if (key_node->right_ != nullptr) {
                successor = FindMin(key_node->right_);
            } else {
                shared_ptr<BinaryTreeNode<T>> pParent = key_node->parent;
                while (pParent != nullptr && pParent->right_ == successor) {
                    successor = pParent;
                    pParent = pParent->parent;
                }
                successor = pParent;
            }
        }

        return successor;
    }

    shared_ptr<BinaryTreeNode<T>>
    FindPredecessor(T data)
    {

    }

    size_t 
    Size() const
    {
        return n_;
    }

    shared_ptr<BinaryTreeNode<T>> 
    Find(T data) const
    {
        shared_ptr<BinaryTreeNode<T>> pTmp(root_);

        while (pTmp != nullptr && pTmp->data_ != data) {
            if (data < pTmp->data_) {
                pTmp = pTmp->left_;
            } else {
                pTmp = pTmp->right_;
            }
        }

        return pTmp;
    }

    bool 
    Empty() const
    {
        return n_ == 0;
    }

    void 
    Inorder(vector<T>& inorder)
    {
        InorderHelper(root_, inorder);
    }

    void
    Postorder(vector<T>& postorder)
    {
        PostorderHelper(root_, postorder);
    }

    void 
    Preorder(vector<T>& preorder)
    {
        PreorderHelper(root_, preorder);
    }

private:
    void InorderHelper(shared_ptr<BinaryTreeNode<T>>& node, vector<T>& inorder)
    {
        if (node != nullptr) {
            InorderHelper(node->left_, inorder);
            inorder.emplace_back(node->data_);
            InorderHelper(node->right_, inorder);
        }
    }

    void PostorderHelper(shared_ptr<BinaryTreeNode<T>>& node, vector<T>& postorder)
    {
        if (node != nullptr) {
            PostorderHelper(node->left_, postorder);
            PostorderHelper(node->right_, postorder);
            postorder.emplace_back(node->data_);
        }
    }

    void PreorderHelper(shared_ptr<BinaryTreeNode<T>>& node, vector<T>& preorder)
    {
        if (node != nullptr) {
            preorder.emplace_back(node->data_);
            PreorderHelper(node->left_, preorder);
            PreorderHelper(node->right_, preorder);
        }
    }

    shared_ptr<BinaryTreeNode<T>> FindMin(const shared_ptr<BinaryTreeNode<T>>& tree)
    {
        shared_ptr<BinaryTreeNode<T>> min_node(tree);
        while (min_node->left_ != nullptr) {
            min_node = min_node->left_;
        }
        return min_node;
    }

    shared_ptr<BinaryTreeNode<T>> FindMax(const shared_ptr<BinaryTreeNode<T>>& tree)
    {
        shared_ptr<BinaryTreeNode<T>> max_node(tree);
        while (max_node->right_ != nullptr) {
            max_node = max_node->right_;
        }
        return max_node;
    }

    shared_ptr<BinaryTreeNode<T>> root_;
    size_t n_;
};
}
#endif

