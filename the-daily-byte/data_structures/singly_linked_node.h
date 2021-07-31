#ifndef SINGLY_LINKED_NODE_H_
#define SINGLY_LINKED_NODE_H_

#include <vector>

namespace data_structures {

using std::vector;

template <typename T>
struct Node
{
    Node* next_;
    T data_;

    Node();
    Node(T n);
};

template <>
struct Node<int>
{
    Node* next_;
    int data_;

    Node(): next_(nullptr), data_(0) {};
    Node(int n): next_(nullptr), data_(n) {};
};

Node<int>* construct_linked_list(const vector<int>& v);

void free_linked_list(Node<int>* head);

bool linked_lists_equal(Node<int>* left, Node<int>* right);

void print_list(Node<int>*& head);

}

#endif // SINGLY_LINKED_NODE_H_
