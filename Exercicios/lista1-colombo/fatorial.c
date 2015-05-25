#include <stdio.h>

int main() {
	int a, b, i;

	while(scanf("%d", &a) != EOF) {
		for (i = 1, b = 1; i <= a; i++) b *= i;
		printf("%d\n", b);
	}

	return 0;
}
