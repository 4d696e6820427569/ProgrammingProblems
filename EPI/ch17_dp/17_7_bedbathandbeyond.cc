/**
 * EPI Chapter 17 DP
 *
 * Suppose you are designing a search engine. In addition to getting keywords
 * from a page's content, you would like to get keywords from Uniform Resource
 * Locators (URLs). For example, bedbathandbeyond.com yields the keywords
 * "bed, bath, beyond, bat, hand": the first 2 coming from the decomposition
 * "bed bath beyond" and the latter 2 coming from the decomposition "bed bat
 * hand beyond".
 *
 * Given a dictionary, i.e., a set of strings, and a name, design an efficient
 * algorithm that checks whether the name is the concatenation of a sequence of
 * dictionary words. If such a concatenation exists, return it. A dictionary
 * word may appear more than once in the sequence. e.g., "a", "man", "a",
 * "plan", "a", "canal" is a valid sequence for "amanaplanacanal".
 *
 * Hint: Solve the generalized problem, i.e., determine for each prefix of the
 * name whether it is the concatenation of dictionary words.
 */

#include <unordered_set>
#include <vector>
#include <string>

using std::unordered_set;
using std::string;
using std::vector;

/**
 * The BF solution: We can try to check if the given name is a substring of
 * every single concatenation of the words from the dictionary.
 * There are an order of n! such concatenations, given that we have n
 * words in our dictionary since we can choose to include a string
 * s_i in the concatenation or not. Searching for the name string will take
 * O(L) where L is the maximum possible length of the concatenation.
 * Thus, the time complexity of the BF solution is somewhere around O(L 2^n).
 *
 * It is inefficient because we try to generate all possible concatenations,
 * even for concatenations that are shorter than the given name string.
 *
 * Idea:  
 */
vector<string> DecomposeIntoDictionaryWords(const string& domain, 
        const unordered_set<string>& dictionary)
{
    vector<string> res;
    return res;
}

int main()
{
    return 0;
}
