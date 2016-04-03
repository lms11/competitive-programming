#include <stdio.h>

int main() {
	int e, m, count, pi;

	scanf("%d", &e);

	while(e--) {
		scanf("%d", &m);
		count = 3 * m;

		while(m--) {
			scanf("%d", &pi);

			count -= 3 * pi;
		}

		if (count >= 0) printf("nao precisa\n");
		else printf("precisa\n");
	}

	return 0;
}