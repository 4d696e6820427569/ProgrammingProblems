/**
 * Singly linked list template.
 */

#ifndef SINGLY_LINKED_LIST_HPP_
#define SINGLY_LINKED_LIST_HPP_

#include <memory>
#include <cstdio>

using std::shared_ptr;
using std::make_shared;

namespace data_structures
{
template <class T>
class ListNode
{
public:
    ListNode() : next_(nullptr), prev_(nullptr) {};
    ListNode(T data) : data_(data), next_(nullptr), prev_(nullptr) {};
    ListNode(const ListNode& ln) : data_(ln.data_), next_(ln.next_) {};
    ~ListNode() = default;
    ListNode& operator=(const ListNode& ln)
    {
        this->data_ = ln.data_;
        this->next_ = ln.next_;
    }

    void setData(T data) { this->data_ = data; }
    void setNext(shared_ptr<ListNode<T>> next) { this->next_ = next; }
    void setPrev(shared_ptr<ListNode<T>> prev) { this->prev_ = prev; }
    T getData() const { return data_; }
    shared_ptr<ListNode<T>> getNext() const { return next_; }
    shared_ptr<ListNode<T>> getPrev() const { return prev_; }

    bool operator==(const ListNode<T>& ln) const
    {
        shared_ptr<ListNode<T>> pTmp1 = this;
        shared_ptr<ListNode<T>> pTmp2 = &ln;

        while (pTmp1 != nullptr && pTmp2 != nullptr) {
            if (pTmp1->getData() != pTmp2->getData()) return false;
            pTmp1 = pTmp1->getNext();
            pTmp2 = pTmp2->getNext();
        }

        if (pTmp1 != nullptr || pTmp2 != nullptr) return false;
        return true;
    }

private:
    T data_;
    shared_ptr<ListNode<T>> next_;
    shared_ptr<ListNode<T>> prev_;
};

template <class T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head_(nullptr), n_(0) {};
    SinglyLinkedList(std::initializer_list<T> init) : head_(nullptr), n_(init.size())
    {
        shared_ptr<ListNode<T>> tmp = head_;
        for (const auto it = init.begin(); it != init.end(); it++) {
            shared_ptr<ListNode<T>> new_node = make_shared<ListNode<T>>(ListNode<T>(*it));
            if (tmp != nullptr) {
                tmp->SetNext(new_node);
            }
            tmp = new_node;
        }
    };

    SinglyLinkedList(const SinglyLinkedList& ln)
    {
        
    };

    SinglyLinkedList& operator=(const SinglyLinkedList& sll)
    {

    };

    ~SinglyLinkedList() = default;

    /// Capacity
    bool Empty() { return n_ == 0; }

    size_t Size() { return n_; }

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
            shared_ptr<ListNode<T>> tmp = head_;
            while (tmp->getNext() != nullptr) {
                tmp = tmp->getNext();
            }

            tmp->setNext(new_node);
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
        head_ = new_node;
        n_++;
    }

    void EmplaceAfter(T data, size_t pos)
    {
        
    }

    /*
     * Remove the first occurrence of data in the linked list.
     */
    void Delete(T data)
    {
        shared_ptr<ListNode<T>> tmp = head_;
        while (tmp != nullptr) {
            if (tmp->getData() == data) {
                if (tmp == head_) {
                    
                } else {
                    
                }
                n_--;
            }
        }
    };

    /**
     * Find the first occurrence of data in the linked list.
     */
    shared_ptr<ListNode<T>> Find(T data)
    {
        shared_ptr<ListNode<T>> tmp = head_;
        while (tmp != nullptr)  {
            if (tmp->getData() == data) {
                return tmp;
            }
            tmp = tmp->getNext();
        }
        return nullptr;
    };

private:
    shared_ptr<ListNode<T>> head_;
    size_t n_;
};
};
#endif
