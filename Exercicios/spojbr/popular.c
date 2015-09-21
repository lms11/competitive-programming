#include <stdio.h>

int main() {
	int count[105], n, a;

	while(scanf("%d", &n), n != 0) {
		for (int x = 0; x < n; x++) count[x] = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a);
				if (a == 1) count[j]++;
			}
		}

		a = 0;
		for (int x = 0; x < n; x++) {
			if (count[x] > a) a = count[x];
		}

		printf("%d\n", a);
	}
}
