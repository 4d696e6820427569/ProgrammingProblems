#include<stdio.h>

int main() {
    int t, n_s, n, l, r;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n_s);
        scanf("%d", &l);
        r = l; n_s--;
        while(n_s--) {
            scanf("%d", &n);
            if (n < l)
                l = n;
            if (n > r)
                r = n;
        }
        printf("%d\n", 2 * (r - l));
    }
    return 0;
}
