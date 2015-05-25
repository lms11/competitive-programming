#include <stdio.h>

int main() {
	long long int tri[30][30];
	long long int soma[30];
	int i, j;

	// i = 2, j =
	for (i = 0; i <= 20; i++) {
		soma[i] = 0;

		for (j = 0; j <= 20; j++) {
			if (j < (2*i + 1)) {
				if (j == 0 || j == 2*i) tri[i][j] = 1;
				else if (j >= 2) tri[i][j] = tri[i-1][j-2] + tri[i-1][j-1] + tri[i-1][j];
				else if (j == 1) tri[i][j] = tri[i-1][j-1] + tri[i-1][j];

			} else {
				tri[i][j] = 0;
			}

			soma[i] += tri[i][j];
		}
	}

	while(scanf("%d", &i) != EOF) {
		printf("%lld\n", soma[i]);
	}

	return 0;
}