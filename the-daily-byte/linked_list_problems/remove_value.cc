/**
 * The Daily Byte 06/04/2021
 *
 * Given a linked list and a value, remove all nodes containing the provided
 * value, and return the resulting list.
 */

#include <vector>
#include <cassert>

#include "../data_structures/singly_linked_node.h"

using std::vector;
using data_structures::Node;
using data_structures::construct_linked_list;
using data_structures::linked_lists_equal;

void remove_value(Node<int>*& head, int data)
{
    Node<int>* tmp = head;
    Node<int>* prev = nullptr;

    while (tmp != nullptr) {
        if (tmp->data_ == data) {
            // Check if this node is head.
            if (prev == nullptr) {
                head = tmp->next_;
            } else {
                prev->next_ = tmp->next_;
            }

            Node<int>* more_tmp = tmp;
            tmp = tmp->next_;
            delete more_tmp;

        } else {
            prev = tmp;
            tmp = tmp->next_;
        }
    }
}

int main()
{
    vector<int> tc1 {1, 2, 3};
    vector<int> tc1_res {1, 2};
    int tc1_n = 3;
    
    Node<int>* tc1_list = construct_linked_list(tc1);
    Node<int>* tc1_res_list = construct_linked_list(tc1_res);
    remove_value(tc1_list, tc1_n);
    assert(linked_lists_equal(tc1_list, tc1_res_list));

    vector<int> tc2 {8, 1, 1, 4, 12};
    vector<int> tc2_res {8, 4, 12};
    int tc2_n = 1;

    Node<int>* tc2_list = construct_linked_list(tc2);
    Node<int>* tc2_res_list = construct_linked_list(tc2_res);
    remove_value(tc2_list, tc2_n);
    assert(linked_lists_equal(tc2_list, tc2_res_list));

    vector<int> tc3 {7, 12, 2, 9};
    vector<int> tc3_res {12, 2, 9};
    int tc3_n = 7;

    Node<int>* tc3_list = construct_linked_list(tc3);
    Node<int>* tc3_res_list = construct_linked_list(tc3_res);
    remove_value(tc3_list, tc3_n);
    assert(linked_lists_equal(tc3_list, tc3_res_list));
    
    vector<int> tc4 {1, 1, 1, 1};
    vector<int> tc4_res {};
    int tc4_n = 1;

    Node<int>* tc4_list = construct_linked_list(tc4);
    Node<int>* tc4_res_list = construct_linked_list(tc4_res);
    remove_value(tc4_list, tc4_n);
    assert(linked_lists_equal(tc4_list, tc4_res_list));

    return 0;
}
