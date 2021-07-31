/**
 * Daily Byte 05/20/2021
 *
 * Given a string, return whether or not it forms a palindrome ignoring case
 * and non-alphabetical characters
 */

#include <string>
#include <algorithm>
#include <cassert>

bool is_palindrome(const std::string& s)
{
    size_t n = s.length();
    size_t i = 0, j = n-1;
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}


int main()
{
    std::string tc1("level");
    std::string tc1_reverse(tc1);
    std::reverse(tc1_reverse.begin(), tc1_reverse.end());
    assert((tc1_reverse == tc1) == is_palindrome(tc1));

    std::string tc2("algorithm");
    std::string tc2_reverse(tc2);
    std::reverse(tc2_reverse.begin(), tc2_reverse.end());
    assert((tc2_reverse == tc2) == is_palindrome(tc2));
    
    std::string tc3("A man, a plan, a canal: Panama.");
    std::string tc3_reverse(tc3);
    std::reverse(tc3_reverse.begin(), tc3_reverse.end());
    assert((tc3_reverse == tc3) == is_palindrome(tc3));
    return 0;
}
