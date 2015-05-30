/* Problema: http://br.spoj.com/problems/PRIMO/ */

#include <stdio.h>

int main() {
	int a, n, s;

	while(scanf("%d", &a) != EOF) {
		s = 0;
		for(n = 2; n < a; n++) {
			if (a % n == 0) {
				s = 1;
				printf("nao\n");
				break;
			}
		}

		if (s == 0) printf("sim\n");
	}

	return 0;
}
