/**
 * The Daily Byte 06/14/2021
 *
 * Create a class CallCounter that tracks the number of calls a client has made
 * within the last 3 seconds. Your class should contain one method,
 *  ping(int t)
 *
 * that receives the current timestamp (in milliseconds) of a new call being
 * made within the last 3 seconds.
 *
 * Note: you may assume that the time associated with each subsequent call to
 * ping is strictly increasing.
 */

#include <cassert>

class CallCounter
{
public:
    CallCounter()
        : call_counter_(0)
        , last_ping_time_elapsed_(0) 
        , expiration_time_(3000)
    {};
    ~CallCounter() = default;
    CallCounter(const CallCounter&) = delete;
    CallCounter& operator=(const CallCounter&) = delete;

    int ping(int t)
    {
        call_counter_++;
        if ((t - last_ping_time_elapsed_) >= expiration_time_)
            call_counter_ -= 1;

        last_ping_time_elapsed_ = t;
        return call_counter_;
    }

private:
    int call_counter_;
    int last_ping_time_elapsed_;
    int expiration_time_;
};

int main()
{
    CallCounter tc1;
    assert(tc1.ping(1) == 1);
    assert(tc1.ping(300) == 2);
    assert(tc1.ping(3000) == 3);
    assert(tc1.ping(3002) == 3);
    assert(tc1.ping(7000) == 1);
    return 0;
}
