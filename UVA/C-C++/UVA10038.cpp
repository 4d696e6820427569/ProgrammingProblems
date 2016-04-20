#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	while (scanf("%d", &n) != EOF && n > 0) {
		int i, a, b; i = n - 1;
		scanf("%d", &a);
		if (i == 0) 
			printf("Jolly\n");
		else {
			int c = 0; vector<bool> array(n-1);
			while (i--) {
				scanf("%d", &b);
				if (abs(b - a) <= n - 1 && !array[abs(b - a) - 1]) 
					array[abs(b - a) - 1] = true; a = b; c++;
			}
			
			if (c == n - 1) printf("Jolly\n");
			else printf("Not jolly\n");
		}
	}
	return 0;
}