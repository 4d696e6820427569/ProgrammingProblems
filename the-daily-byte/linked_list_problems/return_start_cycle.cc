/**
 * The Daily Byte 06/07/2021
 *
 * Given a potentially cyclical linked list where each value is unique, return
 * the node at which the cycle starts. if the list does not contain a cycle,
 * return null.
 */

#include <vector>
#include <cassert>
#include <unordered_map>

#include "../data_structures/singly_linked_node.h"

using std::vector;
using std::unordered_map;

using data_structures::Node;
using data_structures::construct_linked_list;
using data_structures::free_linked_list;

Node<int>* return_start_of_cycle(Node<int>*& head)
{
   Node<int>* tmp = head;
   unordered_map<int, int> m;
   while (tmp != nullptr) {
        if (m.find(tmp->data_) != m.end()) return tmp;
        m[tmp->data_] = 1;
        tmp = tmp->next_;
   }

   return nullptr;
}

int main()
{
    vector<int> tc1 {1, 2, 3};
    Node<int>* tc1_list = construct_linked_list(tc1);
    assert(return_start_of_cycle(tc1_list) == nullptr);
    free_linked_list(tc1_list);

    vector<int> tc2 {1, 2, 3, 4, 5 , 2};
    Node<int>* tc2_list = construct_linked_list(tc2);
    assert(return_start_of_cycle(tc2_list)->data_ == 2);
    free_linked_list(tc2_list);

    vector<int> tc3 {1, 9, 3, 7, 7};
    Node<int>* tc3_list = construct_linked_list(tc3);
    free_linked_list(tc3_list);
    
    return 0;
}
