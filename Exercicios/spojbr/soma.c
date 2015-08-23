/* Problema: http://br.spoj.com/problems/SOMA/ */

#include <stdio.h>

int main() {
	int a, sum, b, i;

	while(scanf("%d", &a) != EOF) {
		sum = 0;
		for (i = 0; i < a; i++) {
			scanf("%d", &b);
			sum += b;
		}
		printf("%d\n", sum);
	}

	return 0;
}
