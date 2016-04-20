#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        string s;
        cin >> s;
        if (s.size() > 10)
            cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
        else 
            cout << s << endl;
    }
    return 0;
}