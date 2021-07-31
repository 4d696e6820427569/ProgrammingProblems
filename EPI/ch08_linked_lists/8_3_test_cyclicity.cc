/**
 * EPI chapter 08 Linked Lists
 *
 * Although a linked list is supposed to be a sequence of nodes ending in null,
 * it is possible to create a cycle in a linked list by making the next field
 * of an element reference to one of the earlier nodes.
 *
 * Write a program that takes the head of a singly linked list and returns null
 * if there does not exist a cycle, and the node at the start of the cycle, if
 * a cycle is present. You do not know the length of the list in advance.
 *
 * Hint: Consider using 2 iterators, one fast and one slow.
 */

#include <cassert>
#include <cstdio>
#include <memory>
#include <unordered_set>

#include "../data_structures/singly_linked_list.hpp"

using std::shared_ptr;
using std::make_shared;
using std::unordered_set;

using data_structures::ListNode;
using pListNode = shared_ptr<ListNode<int>>;

/**
 *  Have an iterator to traverse the entire list.
 *  Have a set data structure that tracks the node that we have visited.
 *  If the next node's pointer is already in the set, return that node.
 *  If our iterator reaches nullptr, return nullptr.
 *
 *  Time complexity: O(n)
 *  Space complexity: O(n)
 *  where n is the length of the list.
 */
pListNode hasCycleSol1(pListNode ll)
{
    pListNode it = ll;
    unordered_set<pListNode> s;
    while (it != nullptr) {
        if (s.count(it) == 0) s.emplace(it);
        else return it;

        it = it->getNext();
    }

    return nullptr;
}

/**
 * Linear time complexity but constant space complexity using 2 pointers.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
pListNode hasCycleSol2(pListNode ll)
{
    pListNode pFast = ll;
    pListNode pSlow = ll;
    
    // What's the condition that we move the pSlow pointer forward?
    // What's the condition that we move the pFast pointer forward?
    // How do you know that you have seen this node before?
    //
    // Always increment move pFast by 2 nodes. Only increment pSlow by
    // 1 node. If there's a cycle, eventually pFast will catch up with
    // pSlow. If there's no cycle, the loop will terminate itself.

    while (pFast->getNext() != nullptr) {
        pFast = pFast->getNext();
        pSlow = pSlow->getNext();

        if (pFast->getNext() != nullptr) {
            pFast = pFast->getNext();
        }

        if (pFast == pSlow) {
            size_t cycleLen = 0;
            do {
                cycleLen++;
                pFast = pFast->getNext();
            } while (pSlow != pFast);
            
            pListNode tmp = ll;
            while (cycleLen--) {
                tmp = tmp->getNext();
            }

            pListNode it = ll;
            while (it != tmp) {
                it = it->getNext();
                tmp = tmp->getNext();
            }

            return it;
        }
    }
    
    return nullptr;
}

int main()
{
    pListNode tc1_head      (new ListNode<int>(0x1));
    pListNode tc1_n1        (new ListNode<int>(0x2));
    pListNode tc1_n2        (new ListNode<int>(0x3));
    pListNode tc1_n3        (new ListNode<int>(0x4));
    pListNode tc1_n4        (new ListNode<int>(0x5));

    tc1_head->setNext(tc1_n1);
    tc1_n1->setNext(tc1_n2);
    tc1_n2->setNext(tc1_n3);
    tc1_n3->setNext(tc1_n4);

    printf("head: %p\n", tc1_head.get());
    printf("n1: %p\n", tc1_n1.get());
    printf("n2: %p\n", tc1_n2.get());
    printf("n3: %p\n", tc1_n3.get());
    printf("n4: %p\n", tc1_n4.get());

    tc1_n4->setNext(tc1_n4);
    printf("hasCycleSol1: %p\n", hasCycleSol1(tc1_head).get());
    printf("hasCycleSol2: %p\n", hasCycleSol2(tc1_head).get());
    assert(hasCycleSol1(tc1_head) == tc1_n4);
    assert(hasCycleSol2(tc1_head) == tc1_n4);

    tc1_n4->setNext(tc1_head);
    assert(hasCycleSol1(tc1_head) == tc1_head);
    assert(hasCycleSol2(tc1_head) == tc1_head);

    tc1_n4->setNext(tc1_n1);
    assert(hasCycleSol1(tc1_head) == tc1_n1);
    assert(hasCycleSol2(tc1_head) == tc1_n1);

    tc1_n4->setNext(tc1_n2);
    assert(hasCycleSol1(tc1_head) == tc1_n2);
    assert(hasCycleSol2(tc1_head) == tc1_n2);

    tc1_n4->setNext(tc1_n3);
    assert(hasCycleSol1(tc1_head) == tc1_n3);
    assert(hasCycleSol2(tc1_head) == tc1_n3);

    tc1_n4->setNext(nullptr);
    assert(hasCycleSol1(tc1_head) == nullptr);
    assert(hasCycleSol2(tc1_head) == nullptr);

    return 0;
}
