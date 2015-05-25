#include <stdio.h>

int main() {
	int c, a1, b1, a2, b2;

	while (scanf("%d", &c) != EOF) {
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

		if (a1 <= c && b1 >= c && a2 <= c && b2 >= c) printf("possivel\n");
		else printf("impossivel\n");
	}

	return 0;
}