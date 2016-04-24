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
#define PG(g, s) {FOR (i, s) { FOR(j, s) printf("%d\t", g[i][j]);printf("\n");}}

using namespace std;

/*
 * TopCoder Collegiate Challenge Semifinal Round 4 - Division I, Level One
 * Circuits
 */
class Circuits {
    public:
    static int howLong(vector<string> connects, vector<string> costs) {
        int** g = constructGraph(connects, costs);
        int n = connects.size(); int maxW = -1;
        FOR(i, n) {
            maxW = max(maxW, dfs(g, i, n, -1));
        }
        return maxW;
    }
    
    static int dfs(int** g, int v, int n, int p) {
        int maxW = 0;
        
        FOR(i, n) {
            if (i != p && g[v][i] != -1)
                maxW = max(maxW, dfs(g, i, n, v) + g[v][i]);
        }
        
        return maxW;
    }
    
    static int** constructGraph(vector<string> connects, vector<string> costs) {
        int** g = new int*[connects.size()];
         
        FOR (i, connects.size()) {
            g[i] = new int[connects.size()];
            FOR (j, connects.size()) g[i][j] = -1; g[i][i] = 0;
            istringstream c( connects[i] );
            istringstream e( costs[i] );
            int n, w;
            while(c >> n && e >> w)
                g[i][n] = w;
        }
    
        return g;
    }
    
        
};

int main() {
    printf("Testing graph construction...\n");
    vector<string> connects = {"1 2", "2", ""};
    vector<string> costs = {"5 3", "7", ""};
    
    cout << Circuits::howLong(connects, costs) << endl;
}