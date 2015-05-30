/* Problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1225 */

#include <stdio.h>

int main() {
	int n, max, i, a;
	long long int sum;

	while(scanf("%d", &n), n != 0) {
		sum = max = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &a);
	
			if (a > max) max = a;

			sum += a;
		}

		if (sum % n == 0) printf("%lld\n", max + 1 - (sum/n));
		else printf("-1\n");
	}

	return 0;
}
