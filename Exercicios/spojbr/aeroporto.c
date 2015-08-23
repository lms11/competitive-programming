/* Problema: http://br.spoj.com/problems/AERO/ */

#include <stdio.h>

int main() {
	int aeroportos[110];
	int a, v, max, i, b, c, d;
	int t = 1;

	for (i = 0; i < 110; i++) aeroportos[i] = 0;
		
	while(scanf("%d %d", &a, &v), a != 0) {
		max = 0;

		for (i = 0; i < v; i++) {
			scanf("%d %d", &b, &c);
	
			aeroportos[b] += 1;
			aeroportos[c] += 1;

			if (aeroportos[b] > max) max = aeroportos[b];
			if (aeroportos[c] > max) max = aeroportos[c];
		}

		printf("Teste %d\n", t++);

		for(d = 0, i = 1; i <= a; i++) {
			if (aeroportos[i] == max) {
				if (d++ > 0) printf(" ");
				printf("%d", i);
				d++;
			}
			
			aeroportos[i] = 0;
		}

		printf("\n\n");
	}

	return 0;
}
