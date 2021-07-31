/**
 * The Daily Byte
 * 07/09/2021
 *
 * Given a string of digits, return all possible text messages those digit
 * could send. Note: The mapping of digits to letters is as follows...
 *
 * 0 -> null
 * 1 -> null
 * 2 -> "abc"
 * 3 -> "def"
 * 4 -> "ghi"
 * 5 -> "jkl"
 * 6 -> "mno"
 * 7 -> "pqrs"
 * 8 -> "tuv"
 * 9 -> "wxyz"
 *
 * Example:
 * Input: 23
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 */

#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

void PrintStrVect(const vector<string>& v)
{
    for (const auto& s : v) {
        printf("%s\n", s.c_str());
    }
}

/**
 * The idea is to recursively generate message base on the possible
 * mapping for each character in the string s.
 *
 * Example:
 * Empty string -> returns an empty list.
 * A string with 1 character c -> returns a list of possible mappings for c.
 * A string with n character -> returns a list of possible mappings for s[n-1],
 *  appended to messages generated from the substring of s from 0 to n-2.
 *
 *  Since there can be at most 4 characters for each mapping of digits,
 *
 *  Time complexity: O(n4^n)
 *  Space complexity: O(4^n)
 */


// The mapping from digit to corresponding characters.
static const string Mappings[10] = 
        {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> GenerateMessage(string s)
{
    vector<string> messages;
    if (s.size() == 1) {
        for (const char& c : Mappings[s[0] - '0']) {
            string c_s(1, c);
            messages.emplace_back(c_s);
        }

    } else if (s.size() > 1) {
        vector<string> sub_s = GenerateMessage(s.substr(0, s.size() - 1));
        for (const char& c : Mappings[s[s.size() - 1] - '0']) {
            string c_s(1, c);
            for (const string& s : sub_s) {
                messages.emplace_back(s + c);
            }
        }
    }

    return messages;
}

void GenerateMessageHelper(const string& s, size_t digit, 
        string& partial, vector<string>& possible_messages)
{
    if (digit == s.size()) {
        // All digits are processed, so add partial to possible_messages.
        // We add a copy since subsequent calls modify partial.
        possible_messages.emplace_back(partial);
    } else {
        // Try all possible characters for this digit.
        for (char c : Mappings[s[digit] - '0']) {
            partial[digit] = c;
            GenerateMessageHelper(s, digit + 1, partial, possible_messages);
        }
    }
}

vector<string> GenerateMessageRecursiveOpt(const string& s)
{
    string partial(s.size(), 0);
    vector<string> possible_messages;
    GenerateMessageHelper(s, 0, partial, possible_messages);
    return possible_messages;
}

vector<string> GenerateMessageIterative(string s)
{
    vector<string> possible_messages;

    stack<string> str_stack;

    return possible_messages;
}

int main()
{
    string tc1("23");
    PrintStrVect(GenerateMessageRecursiveOpt(tc1));

    return 0;
}
