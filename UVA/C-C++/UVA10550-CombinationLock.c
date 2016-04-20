#include <stdio.h>

int getDegree(int init, int a, int b, int c) {
    double x, y, z;

    if (a > init) x = (init - a + 40) * 9;
    else x = (init - a) * 9;

    if (b < a) y = (b - a + 40) * 9;
    else y = (b - a) * 9;

    if (c > b) z = (b - c + 40) * 9;
    else z = (b - c) * 9;

    return (1080 + x + y + z);
}

int main(void) {
    int init, a, b, c;

    while((scanf("%d %d %d %d", &init, &a, &b, &c), init || a || b || c)) {
        printf("%d\n", getDegree(init, a, b, c));
    }
    return 0;
}
