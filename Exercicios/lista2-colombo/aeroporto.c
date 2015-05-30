/* Problema: http://br.spoj.com/problems/AERO/ */

#include <stdio.h>

int main() {
	int aeroportos[100];
	int a, v, max, i, b, c;
	int t = 1;
		
	while(scanf("%d %d", &a, &v), a != 0 && v != 0) {
		max = 0;

		for (i = 0; i < v; i++) {
			scanf("%d %d", &b, &c);
			aeroportos[b - 1] += 1;
			aeroportos[c - 1] += 1;

			if (aeroportos[b - 1] > max) max = aeroportos[b - 1];
			if (aeroportos[c - 1] > max) max = aeroportos[c - 1];
		}

		printf("Teste %d\n", t++);

		for(i = 0; i < a; i++) {
			if (aeroportos[i] == max)
				printf("%d ", i + 1);
			
			aeroportos[i] = 0;
		}

		printf("\n\n");
	}

	return 0;
}
