#ifndef DOUBLY_LINKED_LIST_HPP_
#define DOUBLY_LINKED_LIST_HPP_

#include "./singly_linked_list.hpp"

namespace data_structures
{
template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : head_(nullptr), n_(0) {};

    DoublyLinkedList(const std::initializer_list<T>& init)
        : head_(nullptr), n_(init.size())
    {

    };

    DoublyLinkedList(const DoublyLinkedList& dbl)
    {

    };

    DoublyLinkedList& operator=(const DoublyLinkedList& dbl)
    {

    };

    ~DoublyLinkedList() = default;

    /// Capacity.
    size_t Size() const { return n_; }
    bool Empty() const { return n_ == 0; }

    /// Element access
    shared_ptr<ListNode<T>> Front() const { return head_; }

    /// Modifiers
    
    /**
     * Create a new element and append to the back of the list.
     */
    void EmplaceBack(T data)
    {
        shared_ptr<ListNode<T>> new_node = make_shared<ListNode<T>>(ListNode<T>(data));

        if (head_ == nullptr) {
            head_ = new_node;
        } else {
            shared_ptr<ListNode<T>> tail = head_;
            while (tail->getNext() != nullptr) {
                tail = tail->getNext();
            }

            tail->setNext(new_node);
            new_node->setPrev(tail);
        }
        n_++;
    };

    /**
     * Create a new element and append to the front of the list.
     */
    void EmplaceFront(T data)
    {
        shared_ptr<ListNode<T>> new_node = make_shared<ListNode<T>>(ListNode<T>(data));
        new_node->setNext(head_);
        if (head_ != nullptr) head_->setPrev(new_node);
        head_ = new_node;
        n_++;
    };

    /**
     * Find the first occurrence of data in the linked list.
     */
    void Find(T data) const
    {

    };

    /**
     * Delete the first occurrence of data in the linked list.
     */
    void Delete(T data)
    {

    };

private:
    ListNode<T> head_;
    size_t n_;
};
};

#endif
