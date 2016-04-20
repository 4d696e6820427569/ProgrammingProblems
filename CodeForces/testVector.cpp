#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> s;
    s.push_back(1);
    cout << s[0] << endl;
    s.erase(s.begin() + 0);
    return 0;
}
