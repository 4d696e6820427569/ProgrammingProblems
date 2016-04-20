#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FOR(x, size) for (int x = 0; x < size; x++)

using namespace std;


/*
 * TopCoder SRM 203 Round 1 Div 1 Level 1 / Div 2 Level 2
 * Minh Bui
 */

class MatchMaking {
    public:
    string makeMatch(vector<string> namesWomen, vector<string> answersWomen, 
                     vector<string> namesMen, vector<string> answersMen, string queryWoman) {
        int n = namesWomen.size();
        vector <pair <string, string> > women(n);
        vector <pair <string, string> > men(n);FortegS
        FOR(i, n) {
            women[i] = make_pair(namesWomen[i], answersWomen[i]); 
            men[i] = make_pair(namesMen[i], answersMen[i]);
        }
        string lastMen;
        sort(women.rbegin(), women.rend());
        while (!women.empty()) {
            pair<string, string> currW = women.back();
            string wName = currW.first;
            string wAnswer = currW.second;
            vector< pair< int , pair<string, string> > > listMatched;
            int maxMatchedChoice = 0;
            FOR(i, men.size()) {
                pair<string, string> currM = men[i];
                string mName = currM.first;
                string mAnswer = currM.second;
                int matchedAnswers = 0;
                FOR(j, mAnswer.size()) {
                    if (mAnswer[j] == wAnswer[j])
                        matchedAnswers++;
                }
                
                if (matchedAnswers >= maxMatchedChoice) {
                    maxMatchedChoice = matchedAnswers;
                    listMatched.push_back(make_pair(matchedAnswers, currM));
                }
            }
            
            sort(listMatched.rbegin(), listMatched.rend());
            
            vector< pair<string, string> > bestMatch;
            
            int i = 0;
            while (i < listMatched.size() && listMatched[i].first == maxMatchedChoice) {bestMatch.push_back(listMatched[i].second); i++;}
            
            pair<string, string> best = bestMatch[0];
            
            for (int i = 1; i < bestMatch.size(); i++) {
                if (best.first > bestMatch[i].first)
                    best = bestMatch[i];
            }
            
            cout << wName + " is matched to " + best.first << endl;
            
            if (wName == queryWoman) {return best.first;}
            women.pop_back();
            
            FOR(i, men.size()) { if (men[i] == best) men.erase(men.begin() + i);}
        }
        return lastMen;
    }
        
};

int main() {
    // Test cases.
    string nW[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"};
    string aW[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"};
    string nM[] = {"Ed", "Duff", "Chip", "Abe", "Biff"};
    string aM[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};
    vector<string> namesWomen(nW, nW + sizeof(nW) / sizeof(string));
    vector<string> answersWomen(aW, aW + sizeof(aW) / sizeof(string));
    vector<string> namesMen(nM, nM + sizeof(nM) / sizeof(string));
    vector<string> answersMen(aM, aM + sizeof(aM) / sizeof(string));
    string query = "Emily";
    
    MatchMaking* obj = new MatchMaking();
    cout << obj->makeMatch(namesWomen, answersWomen, namesMen, answersMen, query) << endl;
    return 0;
}