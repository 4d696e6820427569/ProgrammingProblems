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

using namespace std;

int main() {
    unsigned long long n, m, a;
    cin >> n; cin >> m; cin >> a;
    cout << (unsigned long long) (ceil(n/(a * 1.0)) * ceil(m/(a * 1.0)));    
    return 0;
}