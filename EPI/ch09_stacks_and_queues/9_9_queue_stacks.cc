/**
 * EPI Chapter 09 Stacks And Queues
 *
 * Implement a queue using stacks
 *
 * Queue insertion and deletion follows first-in, first-out semantics; stack
 * insertion and deletion is last-in, first-out.
 *
 * How would you implement a queue given a library implementing stacks?
 *
 * Hint: It's impossible to solve this problem with a single stack.
 */

#include <stack>
#include <queue>
#include <stdexcept>
#include <cassert>
#include <cstdio>
#include <iostream>

using std::stack;
using std::queue;

template <class T>
class QueueStack
{
public:
    QueueStack() : using_stack_one_(true) {}

    T Front()
    {
        if (stack_one_.empty() && stack_two_.empty())
            throw std::length_error("Front(): Empty queue");
        if (using_stack_one_) {
            while (!stack_one_.empty()) {
                stack_two_.emplace(stack_one_.top());
                stack_one_.pop();
            }
            using_stack_one_ = false;
            return stack_two_.top();
        } else {
            return stack_two_.top();
        }
    }

    void Enqueue(T x)
    {
        stack_one_.emplace(x);
    }

    T Dequeue()
    {
        if (Size() == 0)
            throw std::length_error("Dequeue(): Empty queue");

        if (using_stack_one_) {
            while (!stack_one_.empty()) {
                stack_two_.emplace(stack_one_.top());
                stack_one_.pop();
            }

            using_stack_one_ = false;

        } 

        T res = stack_two_.top();
        stack_two_.pop();

        if (stack_two_.empty())
            using_stack_one_ = true;
        return res;
    }

    size_t Size()
    {
        return stack_one_.size() + stack_two_.size();
    }

    bool Empty()
    {
        return stack_one_.size() + stack_two_.size() == 0;
    }

private:
    stack<T> stack_one_;
    stack<T> stack_two_;
    bool using_stack_one_;
};

int main()
{
    QueueStack<int> qs;
    assert(qs.Empty());
    assert(qs.Size() == 0);

    qs.Enqueue(1);
    assert(qs.Size() == 1);
    assert(!qs.Empty());
    assert(qs.Front() == 1);
    
    qs.Enqueue(2);
    assert(qs.Front() == 1);

    assert(qs.Dequeue() == 1);
    assert(qs.Dequeue() == 2);
    assert(qs.Empty());

    
    for (int i = 0; i < 16; i++) {
        qs.Enqueue(i);
    }
    
    for (int i = 0; i < 16; i++) {
        int x = qs.Dequeue();
        printf("Dequeue %d\n", x);
        assert(x == i);
    }

    qs.Enqueue(3);
    qs.Enqueue(14);
    qs.Enqueue(4);
    qs.Enqueue(123);
    qs.Enqueue(3);

    assert(qs.Dequeue() == 3);
    assert(qs.Dequeue() == 14);
    
    qs.Enqueue(421);
    assert(qs.Dequeue() == 4);
    assert(qs.Dequeue() == 123);
    assert(qs.Dequeue() == 3);
    assert(qs.Dequeue() == 421);
    assert(qs.Empty());
    assert(qs.Size() == 0);

    return 0;
}
