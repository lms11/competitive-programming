#include <stdio.h>

int main() {
	int a, b, sum, c = 1;

	while(scanf("%d", &a), a != 0) {
		sum = 0;
		while (a > 0) {
			scanf("%d", &b);
			sum += b;
			a--;
		}

		printf("Teste %d\n%d\n\n", c++, sum);
	}

	return 0;
}
