/**
 * EPI Chapter 13 Hash tables
 *
 * 13.2 Is an anoynymous letter constructible?
 *
 * Write a program which takes text for an anonymous letter and text for a
 * magazine and determines if it is possible to write the anonymous letter
 * using the magazine. The anonymous letter can be written using the magazine
 * if for each character in the anonymous letter, the number of times it
 * appears in the anonymous letter is no more than the number of times it
 * appears in the magazine.
 *
 * Hint: Count the number of distinct characters appearing in the letter.
 */

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

/**
 * Idea: Count the frequency of each character from the anonymous letter.
 * We also count the frequency of each character from the magazine text.
 *
 * We then, for each <char, freq> from the anonymous letter hash table,
 * check if freq is greater than the frequency of the same character from the
 * magazine hash table. If there's such case, return true.
 *
 * Given that letter_text has n characters.
 * magazine_text has m characters.
 *
 * Time complexity: O(max(n, m))
 * Space complexity: O(m + n)
 */
bool IsLetterConstructibleFromMagazine(const string& letter_text,
        const string& magazine_text)
{
    unordered_map<char, unsigned int> letter_ht;
    unordered_map<char, unsigned int> magazine_ht;

    for (const auto& c : letter_text) {
        if (letter_ht.find(c) == letter_ht.end())
            letter_ht.emplace(c, 0);
        else
            letter_ht[c]++;
    }

    for (const auto& c : magazine_text) {
        if (magazine_ht.find(c) == magazine_ht.end())
            magazine_ht.emplace(c, 0);
        else
            magazine_ht[c]++;
    }

    for (const auto& cq : letter_ht) {
        if (cq.second > magazine_ht.count(cq.first))
            return false;
    }
    return true;
}

bool IsLetterConstructibleFromMagazineEPI(const string& letter_text,
        const string& magazine_text)
{
    unordered_map<char, int> char_freq_for_letter;

    // Compute the frequency for all chars in letter_text.
    for (char c : letter_text)
        char_freq_for_letter[c]++;

    // Check if the characters in magazine_text can cover characters
    // in char_freq_for_letter.
    for (char c : magazine_text) {
        auto it = char_freq_for_letter.find(c);
        if (it != char_freq_for_letter.cend()) {
            it->second--;
        }

        if (it->second == 0) {
            char_freq_for_letter.erase(it);
            if (char_freq_for_letter.empty()) break;
        }
    }

    // Empty char_frequency_for_letter means every char in letter_text can be
    // covered by a character in magazine_text.
    return char_freq_for_letter.empty();
}


int main()
{
    return 0;
}
