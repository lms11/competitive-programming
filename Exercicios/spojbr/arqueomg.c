#include <stdio.h>

int main() {
	int n, a, b;

	scanf("%d", &n);

	while(n--) {
		scanf("%d %d", &a, &b);

		if (a < 0 && b > 0) printf("%d\n", b - a - 1);
		else printf("%d\n", b - a);
	}

	return 0;
}