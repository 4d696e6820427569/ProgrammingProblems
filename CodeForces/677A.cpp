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

/* Problem: 677A
 * Minh Bui
 */

using namespace std;

int main() {
    int n, h, a, c;
    cin >> n >> h;
    c = 0;
    while(n--) {
        cin >> a;
        if (a > h) c++;
        c++;
    }
    cout << c << endl;
    return 0;
}
