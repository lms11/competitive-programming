#include <stdio.h>

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if (a <= b && a <= c && a <= d) printf("S");
	else printf("N");

	return 0;
}
