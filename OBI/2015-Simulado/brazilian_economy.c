#include <stdio.h>

int main() {
	int q, a, i, sum;

	while(scanf("%d", &q) != EOF) {
		for(i = 0; i < q; i++) {
			scanf("%d", &a);
			sum += a;
		}

		if (sum >= 1.0 * q / 2) printf("N\n");
		else printf("Y\n");
	}

	return 0;
}