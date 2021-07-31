/**
 * EPI Chapter 12 Searching
 *
 * 12.5 Compute the real square root
 * Square root computations can be implemented using sophisticated numerical
 * techniques involving iterative methods and logarithms. However, if you
 * were asked to implement a square root function, you would not be expected
 * to know these techniques.
 *
 * Implement a function which takes as input a floating point value and return
 * its square root.
 *
 * Hint: Iteratively compute a sequence of intervals, each contained in the
 * previous interval, that contain the result.
 */

#include <limits>
#include <cstdio>

using namespace std;

enum class Ordering
{
    SMALLER,
    LARGER,
    EQUAL
};

Ordering Compare(const double& a, const double& b)
{
    double diff = (a - b) / b;
    return diff < -numeric_limits<double>::epsilon() ? Ordering::SMALLER
        : diff > numeric_limits<double>::epsilon() ? Ordering::LARGER : Ordering::EQUAL;
}

double RealSqrt(double x)
{
    double left = 1.0, right = x;
    if (x < 1.0) {
        left = x;
        right = 1.0;
    }

    while (Compare(left, right) == Ordering::SMALLER) {
        double mid = left + (right - left) / 2;
        Ordering cmp = Compare(mid * mid, x);
        if (cmp == Ordering::SMALLER) {
            left = mid;
        } else if (cmp == Ordering::LARGER) {
            right = mid;
        } else {
            return mid;
        }
    }
    return left;
}

int IntSqrt(int x)
{
    int left = 0, right = x;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (m * m > x) {
            right = m - 1;
        } else if (m * m <= x) {
            left = m + 1;
        }
    }

    return left-1;
}

int main()
{
    double tc1 = 2;
    printf("Sqrt(%f) = %f\n", tc1, RealSqrt(tc1));

    double tc2 = 124;
    printf("Sqrt(%f) = %f\n", tc2, RealSqrt(tc2));

    double tc3 = 2.25;
    printf("Sqrt(%f) = %f\n", tc3, RealSqrt(tc3));

    double tc4 = 0.25;
    printf("Sqrt(%f) = %f\n", tc4, RealSqrt(tc4));
    return 0;
}
