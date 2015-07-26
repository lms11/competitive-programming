#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int calc(int a, int b, int c) {
	return a/3 + b/3 + c/3 + min(min(a%3, b%3), c%3);
}

int main() {
	int a, b, c;
	int max = 0, n, i, tmp;

	scanf("%d %d %d", &a, &b, &c);

	n = min(min(a, b), c);

	while

	for(i = 0; i <= (n+1)/2; i++) {
		tmp = calc(a-i, b-i, c-i);
		if (i + tmp > max) max = i + tmp;
	}

	printf("%d\n", max);

	return 0;
}