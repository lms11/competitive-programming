#include <stdio.h>

int main() {
	int n, t = 1;
	int a, b;
	int c, d;

	while(scanf("%d", &n), n != 0) {
		a = b = 0;


		printf("Teste %d\n", t++);
		while(n--) {
			scanf("%d %d", &c, &d);

			a += c;
			b += d;

			printf("%d\n", (a-b));
		}

		printf("\n");
	}

	return 0;
}
