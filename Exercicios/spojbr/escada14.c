#include <stdio.h>

int main() {
	//int m[500][500];
	int i, j, n, m, index, tmp, correct;

	scanf("%d %d", &n, &m);

	index = -1;
	correct = 1;

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &tmp);

			if (correct == 1 && j <= index && tmp != 0) correct = 0;
			else if (correct == 1 && j == index+1 && tmp == 0) index = j;
		}

		index++;
	}

	if (correct == 1) printf("S");
	else printf("N");


	return 0;
}
