/* Problema: http://spoj.com/problems/TEST/ */

#include <stdio.h>

int main() {
	int a, i = 0;
	int b[1000000];

	while(scanf("%d", &a), a != 42) b[i++] = a;

	for(a = 0; a < i; a++) printf("%d\n", b[a]);

	return 0;
}
