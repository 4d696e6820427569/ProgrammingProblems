#include <cstdio>

#include "singly_linked_node.h"

using data_structures::Node;

Node<int>* data_structures::construct_linked_list(const vector<int>& v)
{
    size_t n = v.size();
    if ( n == 0 ) return nullptr;

    Node<int>* head_node = new Node<int>(v[0]);
    Node<int>* next_node = head_node;
    Node<int>* prev_node = nullptr;
    for (size_t i = 1; i < n; i++) {
        prev_node = next_node;
        next_node = new Node<int>(v[i]);
        prev_node->next_ = next_node;
    }

    return head_node;
}

void data_structures::free_linked_list(Node<int>* head)
{
    Node<int>* temp = head;
    Node<int>* prev = nullptr;
    while (temp != nullptr) {
        prev = temp;
        temp = temp->next_;
        delete prev;
    }
}

bool data_structures::linked_lists_equal(Node<int>* left, Node<int>* right)
{
    Node<int>* p_left = left;
    Node<int>* p_right = right;
    while (p_left != nullptr && p_right != nullptr) {
        if (p_left->data_ != p_right->data_) return false;
        p_left = p_left->next_;
        p_right = p_right->next_;
    }

    if ( (p_left == nullptr && p_right != nullptr ) ||
            (p_left != nullptr && p_right == nullptr)) return false;

    return true;
}

void data_structures::print_list(Node<int>*& head)
{
    Node<int>* tmp = head;
    while (tmp != nullptr) {
        printf("%d\n", tmp->data_);
        tmp = tmp->next_;
    }
}
