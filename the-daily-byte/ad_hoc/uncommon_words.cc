/**
 * The Daily Byte 06/01/2021
 * Given 2 strings representing sentences, return the words that are not
 * common to both strings (i.e. the words that only appear in one of the
 * sentences). You may assume that each sentence is a sequence of words
 * (without punctuation) correctly separated using space characters.
 */

#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;
using std::istringstream;

vector<string> uncommon_words(const string& s1, const string& s2)
{
    vector<string> result;

    istringstream s1_stream{s1};
    unordered_set<string> s1_table;
    string in("");

    while (s1_stream >> in) {
        s1_table.insert(in);
    }

    istringstream s2_stream{s2};
    unordered_set<string> s2_table;
    while (s2_stream >> in) {
        s2_table.insert(in);
        if (s1_table.find(in) == s1_table.end()) {
            result.push_back(in);
        }
    }

    s1_stream.clear();
    s1_stream.str(s1);
    while (s1_stream >> in) {
        if (s2_table.find(in) == s2_table.end()) {
            result.push_back(in);
        }
    }

    return result;
}

bool solution_match(const vector<string>& v1, const vector<string>& v2)
{
    if (v1.size() != v2.size()) return false;

    for (const auto& s : v1) {
        if (find(v2.begin(), v2.end(), s) == v2.end()) return false;
    }

    for (const auto& s: v2) {
        if (find(v1.begin(), v1.end(), s) == v1.end()) return false;
    }
    return true;
}

int main()
{
    string tc1_s1("the quick");
    string tc1_s2("brown fox");
    vector<string> tc1_res{"the", "quick", "brown", "fox"};
    assert(solution_match(uncommon_words(tc1_s1, tc1_s2), tc1_res));

    string tc2_s1("the tortoise beat the haire");
    string tc2_s2("the tortoise lost to the haire");
    vector<string> tc2_res{"beat", "to", "lost"};
    assert(solution_match(uncommon_words(tc2_s1, tc2_s2), tc2_res));

    string tc3_s1("copper coffee pot");
    string tc3_s2("hot coffee pot");
    vector<string> tc3_res{"copper", "hot"};
    assert(solution_match(uncommon_words(tc3_s1, tc3_s2), tc3_res));
    return 0;
}
