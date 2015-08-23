#include <stdio.h>

int get_sinal(int valor) { return valor < 0 ? 1 : 0; }
long long int absolute_value(long long int valor) { return valor < 0 ? -valor : valor; }

int main() {
	int n, c, sinal, casa, i;
	long long int valores[200000], soma;

	while (scanf("%d", &n) != EOF) {
		sinal = casa = -1;
		
		for(i = 0; i < n; i++) {
			scanf("%d", &c);

			if (c == 0) continue;

			if (casa == -1 || sinal != get_sinal(c)) {
				casa++;
				valores[casa] = c;
				sinal = get_sinal(c);
			
			} else valores[casa] += (long long int) c;
		}

		soma = 0;

		for (i = casa; i >= 0; i--) {
			if (valores[i] > 0) continue;
			if ((i + 2) <= casa && valores[(i+1)] + valores[(i+2)] < 0)
				valores[i] += (valores[(i+1)] + valores[(i+2)]);
			if (valores[i] < soma) soma = valores[i];

			i--;
		}

		printf("%lld\n", absolute_value(soma));
		
	}

	return 0;
}
