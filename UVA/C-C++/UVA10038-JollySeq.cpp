#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, a, b, c, d, i;
    while(scanf("%d", &n) != EOF) {
        if (n == 1) {
            printf("Jolly\n");
            scanf("%d", &a);
        } else {
            i = n - 1; vector<bool> array(n - 1);
            scanf("%d", &a); bool t = true;
            while (i--) {
                scanf("%d", &b); d = abs(b - a);
                if (d <= n - 1 &&
                        d > 0 &&
                        !array[d - 1]) {
                    array[d - 1] = true; a = b;
                }
            }

            for (int j = 0; j < n - 1; ++j) {
            	if (!array[j])
            		t = false;
            }
             if (t) printf("Jolly\n");
            else printf("Not jolly\n");
        }
    }
    return 0;
}