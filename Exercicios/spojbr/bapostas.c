#include <stdio.h>

int main() {
	int soma, cur_soma;
	int n, aux;

	while(scanf("%d", &n), n != 0) {
		soma = -1;
		cur_soma = 0;

		while(n--) {
			scanf("%d", &aux);

			cur_soma += aux;

			if (cur_soma < 0) cur_soma = 0;
			else if (cur_soma > soma) soma = cur_soma;
		}

		if (soma > 0) printf("The maximum winning streak is %d.\n", soma);
		else printf("Losing streak.\n");
	}

	return 0;
}
