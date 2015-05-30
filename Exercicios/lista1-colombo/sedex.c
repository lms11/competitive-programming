/* Problema: http://br.spoj.com/problems/JSEDEX/ */

#include <stdio.h>

int main() {
	int a, b, c, d;

	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
		if (a <= b && a <= c && a <= d) printf("S\n");
		else printf("N\n");
	}

	return 0;
}
