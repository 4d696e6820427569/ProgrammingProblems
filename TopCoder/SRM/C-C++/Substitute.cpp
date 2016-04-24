#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define vi vector<int>
#define vii vector< vector <int> >
#define FOR(x, size) for(int x = 0; x < size; ++x)

using namespace std;
class Substitute {
    public:
    int getValue(string key, string code) {
        string r;
        for (int i = 0; i < code.size(); i++) {
            char c = code[i];
            for (int j = 0; j < key.size(); j++) {
                if (c == key[j]) {
                    if (j != key.size() - 1) s += to_string(j);
                    else s += to_string(0);
                }
            }
        }
        return stoi(r);
    };
};