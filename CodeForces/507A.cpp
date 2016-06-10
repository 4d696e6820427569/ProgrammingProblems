#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, k, c = 0, r;
    cin >> n >> k;
    vector< pair<int , int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> r;
        a[i] = make_pair(r, i+1);
    }
    vector<int> b;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() && k > 0; i++) {
        if (k - a[i].first >= 0) {
            c++;
            k -= a[i].first;
            b.push_back(a[i].second);
        }
    }
    cout << c << endl;
    for (int i = 0; i < b.size(); i++) {
        if (i != b.size() - 1) cout << b[i] << " ";
        else cout << b[i] << endl;
    }
    return 0;
}
