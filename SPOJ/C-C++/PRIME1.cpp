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

void simpleSieve(unsigned long limit, vector<unsigned long> &primes) {
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (unsigned long i = 2; i * i < limit; i++) {
        if (mark[i]) {
            for (unsigned long j = i * 2; j < limit; j += i)
                mark[j] = false;
        }
    }

    for (unsigned long i = 2; i < limit; i++) 
        if (mark[i]) primes.push_back(i);
    return;
}

void segmentedSieve(unsigned long m, unsigned long n) {
    unsigned long limit = floor(sqrt(n)) + 1;
    vector<unsigned long> primes;
    simpleSieve(limit, primes);

    unsigned long low = limit;
    unsigned long high = 2 * limit;

    while (low < n) {
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));


        for (int i = 0; i < primes.size(); i++) {
            unsigned long lowlimit = floor(low/primes[i]) * primes[i];
            if (lowlimit < low)
                lowlimit += primes[i];
        

            for (unsigned long j = lowlimit; j < high; j += primes[i])
                mark[j - low] = false;
        }

        for (unsigned long i = low; i < high; i++)
            if (mark[i - low] && i >= m && i <= n)
                printf("%lu\n", i);

        low += limit;
        high += limit;
        if (high >= n) high = n;
    }
}

int main() {
    int t;
    unsigned long m, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lu %lu", &m, &n);
        segmentedSieve(m, n);
        if (t) printf("\n");
    }
    return 0;
}
