#include <stdio.h>

/*
 * UVA11799 - Horror Dash
 * Minh Bui
 */

int main() {
    int t, max, v, c, n;
    while(scanf("%d", &t) != EOF) {
        c = 1; max = 0;
        while(t--) {
            max = 0;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &v);
                if (v > max) max = v;
            }
            printf("Case %d: %d\n", c, max);
            c++;
        }
    }
    return 0;
}
