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
 * TopCoder SRM 271 Div 1 Level 1 / Div 2 Level 3
 * Minh Bui
 */

class OneFight {
public:
	static bool compare(const pair<int, pair<int, int> > &i, const pair<int, pair<int, int> > &j) {
		return (i.second).first * (j.second).second <= (j.second).first * (i.second).second;
	};
	
	int monsterKilling(vector <int> life, vector <int> damage, int yourDamage) {
		int minLife = 0; int curr = 0;
		pair<int, int> monsters;
		vector< pair<int, pair<int, int> > > lifeDamage(damage.size());
		FOR(i, (life.size())) lifeDamage[i] = make_pair( i, make_pair( ceil(life[i]/(yourDamage * 1.0)), damage[i] ) );
		sort(lifeDamage.begin(), lifeDamage.end(), compare);
		while (curr < life.size()) {
			FOR(i, (life.size())) { if (life[i] > 0) minLife += damage[i]; }
			life[ lifeDamage[curr].first ] -= yourDamage;
			if (life[ lifeDamage[curr].first ] <= 0) curr++;
		}
		return (minLife + 1);
	};
};