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
#define FOR(x, size) for(int x = 0; x < size; ++x)

/* TopCoder - Single Round Match 271 Round 1 - Division II, Level One */

using namespace std;

class CheckFunction {
    public:
    int newFunction(string code) {
        int result = 0;
        int array[] = {6, 2, 5, 5, 4, 5, 6, 7, 3, 7, 6};
        for (int i = 0; i < code.length(); i++) result += array[(int) code[i]];
        return result;
    }
};

int main() {
    CheckFunction *object = new CheckFucntion();
    cout << object->newFunction("13579") << endl;
    cout << object->newFunction("02468") << endl;
    cout << object->newFunction("73254370932875002027963295052175") << endl;
    return 0;
}