#include <stdio.h>

int main() {
	int n, p;
	int count = 0;
	int a, b;

	scanf("%d %d", &n, &p);

	while(n--) {
		scanf("%d %d", &a, &b);
		if (a + b >= p) count++;
	}

	printf("%d", count);

	return 0;
}
