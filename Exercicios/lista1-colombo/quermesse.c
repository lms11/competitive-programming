#include <stdio.h>

int main() {
	int sol[1000000];
	int a, i, n, j = 0;

	while(scanf("%d", &a), a != 0) {
		for (i = 0; i < a; i++) {
			scanf("%d", &n);
			if (n == i + 1) {
				sol[j++] = n;
			}
		}

	}

	for(i = 0; i < j; i++) printf("Teste %d\n%d\n\n", i + 1, sol[i]);

	return 0;
}
