/**
 * EPI - Chapter 07 Strings
 *
 * 06/24/2021
 *
 * For the purpose of this problem, define a palindromic string to be a string
 * which when all the nonalphanumeric are removed it reads the same front to
 * back ignoring case. For example
 *
 * "A man, a plan, a canal, Panama." and
 * "Able was I, ere I saw Elba!"
 * are palindromic, but
 *
 * "Ray a Ray" is not.
 *
 * Implement a function which takes as input a string s and returns true if s
 * is a palindromic string.
 *
 * Hint: Use 2 indices.
 */

#include <string>
#include <cctype>
#include <cassert>

using std::string;

bool is_palindrome(const string& s)
{
    int i = 0, j = static_cast<int>(s.size() - 1);

    while (i < j) {
        while (!isalpha(s[i]) && i < j) s[i++];
        while (!isalpha(s[j]) && j > i) s[j--];

        if (tolower(s[i++]) != tolower(s[j--])) return false;
    }

    return true;
}

int main()
{
    string tc1("A man, a plan, a canal, Panama.");
    assert(is_palindrome(tc1));

    string tc2("Able was I, ere I saw Elba!");
    assert(is_palindrome(tc2));

    string tc3("Ray a Ray");
    assert(!is_palindrome(tc3));
    return 0;
}
