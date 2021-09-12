/**
 * AC C++ Dev Coding P1
 *
 * Given e and n where n is the anchor time in UNIX epox nanoseconds.
 *
 * It's guaranteed that n >= e.
 *
 * Convert the time to Day:Hours:Minutes::Seconds::Miliseconds::Nanoseconds.
 *
 * Constrains:
 * 0 <= Days < 100 (3 digits)
 * 0 <= Hours < 24 (2 digits)
 * 0 <= Minutes < 60 (2 digits)
 * 0 <= Seconds < 60 (2 digits)
 * 0 <= Miliseconds < 1000 (3 digits)
 * 0 <= Nanoseconds < 1000 (3 digits)
 *
 * The output string should be formatted accordingly with 0s prepended as deem
 * appropriate.
 */

#include <string>

std::string GetElapsedTime(unsigned long n, unsigned long e)
{
    std::string res("");
    return res;
}
