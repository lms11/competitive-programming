#include <stdio.h>

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if ((a == c && b != d) || (b == d && a != c)) printf("V");
	else printf("F");

	return 0;
}
