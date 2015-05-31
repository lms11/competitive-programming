/* Problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1089 */

#include <stdio.h>

int main() {
	int p[15000];
	int n, a, i, sum;

	while(scanf("%d", &n), n != 0) {
		for(i = 1; i <= n; i++) scanf("%d", &p[i]);
		p[0] = p[n];
		p[n+1] = p[1];
		sum = 0;

		for(i = 1; i <= n; i++)
			if ((p[i-1] < p[i] && p[i] > p[i+1]) || (p[i-1] > p[i] && p[i] < p[i+1]))
			sum++;
	
		printf("%d\n", sum);
	}

	return 0;
}
