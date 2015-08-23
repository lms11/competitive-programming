/* Problema: http://br.spoj.com/problems/ESTAGIO/ */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, max, cod, med, j, t = 1;
	int *codigos;

	while(scanf("%d", &n), n != 0) {
		max = j = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &cod, &med);
			
			if (med == max) codigos[j++] = cod;
			else if (med > max) {
				free(codigos);
				codigos = malloc(20000 * sizeof(int));
				j = 0;
				codigos[j++] = cod;
				max = med;
			}
		}

		printf("Turma %d\n", t++);
		for (i = 0; i < j; i++) printf("%d ", codigos[i]);
		printf("\n\n");
	}

	return 0;
}
