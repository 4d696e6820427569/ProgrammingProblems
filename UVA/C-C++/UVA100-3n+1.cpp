#include <stdio.h>

unsigned long r(unsigned long n) {
    unsigned long c = 1 ;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        c++;
    }
    return c;

}

int main() {
    unsigned long i, j, a, b, t;
    while (scanf("%lu %lu", &i, &j) != EOF) {
        bool s = false;
        if (i > j) {
            a = i; i = j; j = a; s = true;
        }
        b = t = 0;
        for (a = i; a <= j; a++) {
            t = r(a);
            if (t > b) b = t;
        }
        if (!s) printf("%lu %lu %lu\n", i, j, b);
        else printf("%lu %lu %lu\n", j, i, b);
    }
    return 0;
}

