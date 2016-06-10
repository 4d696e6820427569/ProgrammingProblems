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
#include <cstring>
#include <queue>
#define FOR(i, size) for (int i = 0; i < size; ++i)
#include <stdio.h>

using namespace std;

int main() {
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    string s;
    cin >> s;
    
    return 0;
}

unsigned gcd(unsigned u, unsigned v) {
    while (v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}