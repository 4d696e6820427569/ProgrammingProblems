/**
 * Daily Byte 05/20/2021
 *
 * Given a string, reverse all of its characters and return the resulting
 * string
 */

#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>

std::string reverse_string(std::string& s)
{
    std::string s_reversed("");
    for (auto i = s.rbegin(); i != s.rend(); i++) {
        s_reversed += (*i);
    }
    return s_reversed;
}

int main()
{
    std::string tc1("Cat");
    std::string tc1_reversed = reverse_string(tc1);
    std::reverse(tc1.begin(), tc1.end());
    assert(tc1_reversed == tc1);

    std::string tc2("The Daily Byte");
    std::string tc2_reversed = reverse_string(tc2);
    std::reverse(tc2.begin(), tc2.end());
    assert(tc2_reversed == tc2);
    
    std::string tc3("civic");
    std::string tc3_reversed = reverse_string(tc3);
    std::reverse(tc3.begin(), tc3.end());
    assert(tc3_reversed == tc3);
    return 0;
}
