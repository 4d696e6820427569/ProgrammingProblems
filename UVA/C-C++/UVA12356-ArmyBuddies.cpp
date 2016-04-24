#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	unsigned int s, b, l, r;
	
    vector<int> left(110000), right(110000);
    while (scanf("%d %d", &s, &b), (s || b)) {
        for (int i = 0; i <= s; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        while (b--) {
            scanf("%d %d", &l, &r);
            if (left[l] < 1) printf("* ");
            else printf("%d ", left[l]);
            if (right[r] > s) printf("*\n");
            else printf("%d\n", right[r]);
            
            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        printf("-\n");
    }
    return 0;
}