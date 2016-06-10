#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";

    for (int i = 1; i <= 379; i++) {
        s += to_string(i);
    }
    cout << s[n-1] << endl;
}
