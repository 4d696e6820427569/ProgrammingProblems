#include <stdio.h>

/*
 * UVA11559 - Event Planning
 * Minh Bui
 */

int main() {
    unsigned n, b, h, w, sum, hp, beds, c, min;
    while (scanf("%u %u %u %u", &n, &b, &h, &w) != EOF) {
        bool found = false; min = 0;
        while(h--) {
            scanf("%u", &hp);
            sum = hp * n;
            c = w;
            while(c--) { 
                scanf("%u", &beds);
                if (beds >= n) {found = true; if (min == 0 || sum < min) min = sum;};
            }    
        }
        if (found && min <= b) printf("%u\n", min);
        else printf("stay home\n");
    }
    return 0;
}