#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	int a, t_a, b, t_b;
	string d_time;
	cin >> a >> t_a;
	cin >> b >> t_b;
	cin >> d_time;
	int start = 300 * 60, end = 1439 * 60;
	int init = (stoi(d_time.substr(0, 2)) * 60 + stoi(d_time.substr(3, 2))) * 60;
	int tick = start, i = 0, maxB = 0;
	bool Si = false;
	queue <int> st;
	st.push(start);
	while (tick <= end) {
		if (!st.empty() && tick == st.front() + t_b *60) st.pop();
		if (tick > init && tick < init + t_a * 60) {
			if (!Si) { Si = true; maxB = st.size(); }
		} else Si = false;

		if (i == b * 60) {
			if (Si) maxB++;
			st.push(tick);
			i = 0;
		}
		tick++; i++;
	}
	cout << maxB << endl;
	return 0;
}