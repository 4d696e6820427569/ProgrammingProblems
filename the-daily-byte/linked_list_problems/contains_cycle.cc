/**
 * The Daily Byte 06/06/2021
 *
 * Contains Cycle: Given a linked list, containing unique numbers,
 * return whether or not it has a cycle.
 *
 * Note: A cycle is a circular arrangment (one node points back to a previous
 * node)
 */

#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdio>

#include "../data_structures/singly_linked_node.h"

using std::vector;
using std::string;
using std::unordered_map;
using data_structures::Node;
using data_structures::construct_linked_list;

bool contains_cycle(Node<int>*& head)
{
    unordered_map<int, int> m;
    Node<int>* tmp = head;
    while (tmp != nullptr) {
        if(m.find(tmp->data_) != m.end()) return true;
        m[tmp->data_] = 1;
        tmp = tmp->next_;
    }
    
    return false;
}

int main()
{
    vector<int> tc1 {1, 2, 3, 1};
    Node<int>* tc1_list = construct_linked_list(tc1);
    assert(contains_cycle(tc1_list));

    vector<int> tc2 {1, 2, 3};
    Node<int>* tc2_list = construct_linked_list(tc2);
    assert(!contains_cycle(tc2_list));

    vector<int> tc3 {1, 1};
    Node<int>* tc3_list = construct_linked_list(tc3);
    assert(contains_cycle(tc3_list));

    return 0;
}
