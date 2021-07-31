/**
 * The Daily Byte 06/14/2021
 *
 * Design a class, Moving Average, which contains a method, next that is
 * responsible for returning the moving average from a stream of integers.
 */

#include <queue>
#include <vector>
#include <cassert>

using std::queue;
using std::vector;

class MovingAverage
{
public:
    MovingAverage() : size_(3){};
    MovingAverage(int s) : size_(s){};
    ~MovingAverage() = default;
    MovingAverage(const MovingAverage&) = delete;
    MovingAverage& operator=(const MovingAverage&) = delete;

    double next(int val)
    {
        buffer_.emplace_back(val);
        int buffer_len = static_cast<int>(buffer_.size());
        double res = 0.0;
        if (buffer_len < size_) {
            for (int i = 0; i < buffer_len; i++) {
                res += buffer_[i];
            }
            res /= static_cast<double>(buffer_.size());
        } else {
            for (int i = buffer_len - size_; i < buffer_len ; i++) {
                res += buffer_[i];
            }

            res /= static_cast<double>(size_);
        }
        return res;
    };

private:
    vector<int> buffer_;
    int size_;
};

int main()
{
    MovingAverage tc;
    assert(tc.next(3) == 3 );
    assert(tc.next(5) == 4 );
    assert(tc.next(7) == 5 );
    assert(tc.next(6) == 6 );

    return 0;
}
