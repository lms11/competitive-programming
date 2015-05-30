#include <stdio.h>

int main() {
	char c;
	int n, sum, i, j = 0, sig, b;

	while(scanf("%d", &n), n != 0) {
		sum = 0;
		sig = 1;
		for(i = 0; i < n; i++) {
			scanf("%d", &b);
			sum += sig * b;
			
			if (i < n-1) {
				scanf("%c", &c);
				if (c == '+') sig = 1;
				else if (c == '-') sig = -1;
			}
		}

		printf("Teste %d\n%d\n\n", ++j, sum);
	}

	return 0;
}
