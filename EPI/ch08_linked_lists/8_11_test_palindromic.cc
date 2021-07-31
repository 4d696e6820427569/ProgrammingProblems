/**
 * EPI Chapter 08 Singly linked list
 *
 * Test whether a singly linked list is palindromic.
 *
 * It's straightforward to check whether the sequence stored in an array is a
 * palindrome. However, if this seuqence is stored as a singly linked list,
 * the problem of detecting palindromicity becomes more challenging.
 *
 * Write a program that tests whether a singly linked list is palindromic.
 */

#include <memory>
#include <cassert>
#include <cstdio>

#include "../data_structures/singly_linked_list.hpp"

using std::shared_ptr;
using std::make_shared;

using data_structures::ListNode;

void PrintLinkedList(const shared_ptr<ListNode<int>>& head)
{
    for (shared_ptr<ListNode<int>> iter = head;
            iter != nullptr; iter = iter->getNext()) {
        printf("%d ", iter->getData());
    }
    printf("\n");
}

/**
 * Have 2 iterators moving in tandem after knowing the length of the linked
 * list. Iteratively comparing the first node with the last node, the second
 * node with the second last node, and so on.
 *
 * Time complexity: O(n^2)
 * Space complexty: O(1)
 */
bool IsLinkedListAPalindromeBF(shared_ptr<ListNode<int>> head)
{
    shared_ptr<ListNode<int>> pFirst = head;
    shared_ptr<ListNode<int>> pSecond = head;

    size_t len = 0;
    while (pFirst != nullptr) {
        len++;
        pFirst = pFirst->getNext();
    }

    pFirst = head;
    for(size_t i = 0; i < len / 2; i++) {
        pSecond = pFirst;
        for (size_t j = 0; j < len - 2 * i - 1; j++) {
            pSecond = pSecond->getNext();
        }

        if (pFirst->getData() != pSecond->getData()) return false;
        pFirst = pFirst->getNext();
    }

    return true;
}

/**
 * Reverse a singly linked list. Use 2 iterators
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
void ReverseLinkedList(shared_ptr<ListNode<int>>& head)
{
    if (head == nullptr) return;
    shared_ptr<ListNode<int>> pFirst = head->getNext();
    shared_ptr<ListNode<int>> pSecond = head;

    shared_ptr<ListNode<int>> pTmp = nullptr;
    shared_ptr<ListNode<int>> pPrev = nullptr;
    while (pFirst != nullptr) {
        pTmp = pFirst->getNext();
        pFirst->setNext(pSecond);
        pSecond->setNext(pPrev);
        pPrev = pSecond;
        pSecond = pFirst;
        pFirst = pTmp;
    }

    head = pSecond;
}

/**
 * Use 2 iterators: Fast and slow. When fast reaches the end of the list, slow
 * is at middle. We can reverse the later half of the list and comparing
 * nodes. Reverse the list again to return the list to normal.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> head)
{
    shared_ptr<ListNode<int>> pFast = head;
    shared_ptr<ListNode<int>> pSlow = head;

    while (pFast != nullptr) {
        pFast = pFast->getNext();
        pSlow = pSlow->getNext();

        if (pFast != nullptr)
            pFast = pFast->getNext();
    }

    ReverseLinkedList(pSlow);

    shared_ptr<ListNode<int>> iterBegin = head;
    shared_ptr<ListNode<int>> iterMid = pSlow;
    while (iterMid != nullptr) {
        if (iterBegin->getData() != iterMid->getData()) return false;
        iterBegin = iterBegin->getNext();
        iterMid = iterMid->getNext();
    }

    ReverseLinkedList(pSlow);

    return true;
}

int main()
{
    // Test case 1.
    shared_ptr<ListNode<int>> tc1_head      (make_shared<ListNode<int>>(0x1));
    shared_ptr<ListNode<int>> tc1_n1        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc1_n2        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc1_n3        (make_shared<ListNode<int>>(0x4));
    shared_ptr<ListNode<int>> tc1_n4        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc1_n5        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc1_n6        (make_shared<ListNode<int>>(0x1));

    tc1_head    ->setNext(tc1_n1);
    tc1_n1      ->setNext(tc1_n2);
    tc1_n2      ->setNext(tc1_n3);
    tc1_n3      ->setNext(tc1_n4);
    tc1_n4      ->setNext(tc1_n5);
    tc1_n5      ->setNext(tc1_n6);

    assert(IsLinkedListAPalindromeBF(tc1_head));
    assert(IsLinkedListAPalindrome(tc1_head));
    printf("Test 1 passed.\n");
    
    // Test case 2.
    shared_ptr<ListNode<int>> tc2_head      (make_shared<ListNode<int>>(0x1));
    shared_ptr<ListNode<int>> tc2_n1        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc2_n2        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc2_n3        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc2_n4        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc2_n5        (make_shared<ListNode<int>>(0x1));

    tc2_head    ->setNext(tc2_n1);
    tc2_n1      ->setNext(tc2_n2);
    tc2_n2      ->setNext(tc2_n3);
    tc2_n3      ->setNext(tc2_n4);
    tc2_n4      ->setNext(tc2_n5);

    assert(IsLinkedListAPalindromeBF(tc2_head));
    assert(IsLinkedListAPalindrome(tc2_head));
    printf("Test 2 passed.\n");
    
    // Test case 3.
    shared_ptr<ListNode<int>> tc3_head      (make_shared<ListNode<int>>(0x1));

    assert(IsLinkedListAPalindromeBF(tc3_head));
    assert(IsLinkedListAPalindrome(tc3_head));
    printf("Test 3 passed.\n");

    // Test case 4.
    shared_ptr<ListNode<int>> tc4_head      (make_shared<ListNode<int>>(0x1));
    shared_ptr<ListNode<int>> tc4_n1        (make_shared<ListNode<int>>(0x6));
    shared_ptr<ListNode<int>> tc4_n2        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc4_n3        (make_shared<ListNode<int>>(0x4));
    shared_ptr<ListNode<int>> tc4_n4        (make_shared<ListNode<int>>(0x12));
    shared_ptr<ListNode<int>> tc4_n5        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc4_n6        (make_shared<ListNode<int>>(0x4));

    tc4_head    ->setNext(tc4_n1);
    tc4_n1      ->setNext(tc4_n2);
    tc4_n2      ->setNext(tc4_n3);
    tc4_n3      ->setNext(tc4_n4);
    tc4_n4      ->setNext(tc4_n5);
    tc4_n5      ->setNext(tc4_n6);

    assert(!IsLinkedListAPalindromeBF(tc4_head));
    assert(!IsLinkedListAPalindrome(tc4_head));
    printf("Test 4 passed.\n");
    
    // Test case 5.
    shared_ptr<ListNode<int>> tc5_head      (make_shared<ListNode<int>>(0x1));
    shared_ptr<ListNode<int>> tc5_n1        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc5_n2        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc5_n3        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc5_n4        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc5_n5        (make_shared<ListNode<int>>(0x1));

    tc5_head    ->setNext(tc5_n1);
    tc5_n1      ->setNext(tc5_n2);
    tc5_n2      ->setNext(tc5_n3);
    tc5_n3      ->setNext(tc5_n4);
    tc5_n4      ->setNext(tc5_n5);

    assert(!IsLinkedListAPalindromeBF(tc5_head));
    assert(!IsLinkedListAPalindrome(tc5_head));
    printf("Test 5 passed.\n");

    // Test reverse linked list.
    shared_ptr<ListNode<int>> tc_rev_head      (make_shared<ListNode<int>>(0x1));
    shared_ptr<ListNode<int>> tc_rev_n1        (make_shared<ListNode<int>>(0x2));
    shared_ptr<ListNode<int>> tc_rev_n2        (make_shared<ListNode<int>>(0x3));
    shared_ptr<ListNode<int>> tc_rev_n3        (make_shared<ListNode<int>>(0x4));
    shared_ptr<ListNode<int>> tc_rev_n4        (make_shared<ListNode<int>>(0x5));
    shared_ptr<ListNode<int>> tc_rev_n5        (make_shared<ListNode<int>>(0x6));
    shared_ptr<ListNode<int>> tc_rev_n6        (make_shared<ListNode<int>>(0x7));

    tc_rev_head    ->setNext(tc_rev_n1);
    tc_rev_n1      ->setNext(tc_rev_n2);
    tc_rev_n2      ->setNext(tc_rev_n3);
    tc_rev_n3      ->setNext(tc_rev_n4);
    tc_rev_n4      ->setNext(tc_rev_n5);
    tc_rev_n5      ->setNext(tc_rev_n6);

    PrintLinkedList(tc_rev_head);
    printf("Reversing:\n");
    ReverseLinkedList(tc_rev_head);
    PrintLinkedList(tc_rev_head);

    return 0;
}
