#include <stdio.h>

int inverte(int a) {
	int b = 0;

	while (a > 0) {
		b *= 10;
		b += a % 10;
		a /= 10;
	}

	return b;
}

int main() {
	int n;
	int a, b;

	scanf("%d", &n);

	while(n--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", inverte(inverte(a) + inverte(b)));
	}

	return 0;
}
