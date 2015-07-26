#include <stdio.h>

int main() {
	char a, b, c;
	int mais = '+' + '+',
		menos = '-' + '-';
	int result = 0, n;

	scanf("%d", &n);

	while(n--) {
		scanf(" %c%c%c", &a, &b, &c);
		if (a + b + c - 'X' == mais) result++;
		else result--;
	}

	printf("%d\n", result);

	return 0;
}