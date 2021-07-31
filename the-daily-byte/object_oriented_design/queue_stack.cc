/**
 * The Daily Byte 06/15/2021
 *
 * Design a class to implement a stack using only a single queue. Your class,
 * QueueStack, should support the following stack methods: push()
 * (adding an item), pop() (removing an item), peek()
 * (returning the top value without removing it), and empty()
 * (whether or not the stack is empty).
 *
 * Assumption:
 *  queue supports the following operations:
 *      push() -- add an element to the queue.
 *      pop() -- remove the front element.
 *      peek() -- return the front element.
 *      empty() -- return true if the queue is empty.
 *      size() -- return the size of the queue.
 */

#include <queue>
#include <stack>
#include <cassert>

using std::stack;
using std::queue;

class QueueStack
{
public:
    QueueStack() = default;
    QueueStack(const QueueStack&) = delete;
    ~QueueStack() = default;
    QueueStack& operator=(QueueStack&) = delete;

    void push(int new_elem)
    {
        inner_queue_.emplace(new_elem);
    };

    void pop()
    {
        if (empty()) return;
        // Move the last element to the front by doing left shift
        // (n-1) times where n is the size.
        size_t n = inner_queue_.size();
        for (size_t i = 0; i < n - 1; i++) {
            inner_queue_.emplace(inner_queue_.front());
            inner_queue_.pop();
        }

        inner_queue_.pop();
    };

    int peek()
    {
        // Move the last element to the front. Return it, and rotate back.
        // Rotate left (n-1) times and 1 more time.
        size_t n = inner_queue_.size();
        for (size_t i = 0; i < n - 1; i++) {
            inner_queue_.emplace(inner_queue_.front());
            inner_queue_.pop();
        }

        int res = inner_queue_.front();
        inner_queue_.emplace(inner_queue_.front());
        inner_queue_.pop();
        return res;

    };

    bool empty()
    {
        return inner_queue_.empty();
    }


private:
    queue<int> inner_queue_;
};

int main()
{
    QueueStack tc1_qs;
    assert(tc1_qs.empty());
    tc1_qs.push(3);
    assert(tc1_qs.peek() == 3);
    tc1_qs.push(2);
    assert(tc1_qs.peek() == 2);
    tc1_qs.push(1);
    assert(tc1_qs.peek() == 1);
    tc1_qs.push(0);
    assert(tc1_qs.peek() == 0);

    tc1_qs.pop();
    assert(tc1_qs.peek() == 1);
    tc1_qs.pop();
    assert(tc1_qs.peek() == 2);
    tc1_qs.pop();
    assert(tc1_qs.peek() == 3);
    tc1_qs.pop();
    assert(tc1_qs.empty());

    return 0;
}
