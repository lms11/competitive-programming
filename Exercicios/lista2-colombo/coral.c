/* Problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1225 */

#include <stdio.h>

int abs(int a) { return a < 0 ? -a : a; }

int main() {
	int n, i, a;
	long long int sum;

	scanf("%d", &n);

		sum = max = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &a);

			sum += a;
		}

		if (sum % n == 0) printf("%lld", max + 1 - (sum/n));
		else printf("-1");

	return 0;
}
