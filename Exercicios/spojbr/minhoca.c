#include <stdio.h>

int j_sum[100];

int main() {
	int v[100][100];
	int a, b, i, j, max, tmp_sum;

	scanf("%d %d", &a, &b);

	max = 0;

	for(i = 0; i < a; i++) {
		tmp_sum = 0;

		for(j = 0; j < b; j++) {
			scanf("%d", &v[i][j]);
			tmp_sum += v[i][j];
			j_sum[j] += v[i][j];
	
			if (j_sum[j] > max) max = j_sum[j];
		}

		if (tmp_sum > max) max = tmp_sum;
	}

	printf("%d", max);

	return 0;
}
