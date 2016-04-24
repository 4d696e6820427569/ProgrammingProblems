#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * UVA 10114 - Loansome Car Buyer
 * Minh Bui
 */

int main() {
    int m, r, i, c;
    float p, l, o, income;
    while(true) {
        scanf("%d %f %f %d", &m, &p, &l, &r);
        if (m < 0) break;
        float table[m + 1]; c = i = 0;
        memset(table, 0, sizeof(float));
        while(r--) {
            scanf("%d", &i);
            while(c < i) {              
                table[c] = table[c - 1];
                c++;
            }
            
            scanf("%f", &table[i]); c++;
        }
        
        while(i < (m + 1)) {i++; table[i] = table[i-1];}
        
        income = l/m;
        o = l; i = 1;
        l = (l + p) * (1.0 - table[0]);
        while (o > l) {
            o -= income;
            l -= l * table[i];
            i++;
        }
        
        if (i - 1 != 1) printf("%d months\n", i-1);
        else printf("%d month\n", i-1);
        
    }
    return 0;
}