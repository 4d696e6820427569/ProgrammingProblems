#include <stdio.h>
#include <iostream>
#define FOR(n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int scores[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &scores[i]);

    int c = 0;
    int kscore = scores[k-1];
    for (int i = 0; i < n; i++)
        if (scores[i] >= kscore && scores[i] > 0) c++;


    printf("%d\n", c);

    return 0;
}
