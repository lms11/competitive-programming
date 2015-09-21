#include <stdio.h>

int fatorial(int x) {
	int n = 1;
	for (int y = 1; y <= x; y++) n *= y;
	return n;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fatorial(n));
	return 0;
}
