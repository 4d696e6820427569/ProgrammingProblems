#include <stdio.h>

int main() {
    int w;
    scanf("%d", &w);
    for (int i = 2; i < w; i += 2) {
        if ((w - 2) % 2 == 0) {printf("YES\n"); return 0;}
    }
    printf("NO\n");
    return 0;
}