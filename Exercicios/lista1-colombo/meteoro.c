#include <stdio.h>

int main() {
	int x1, y1, x2, y2;
	int n, x, y, i, cairam;
	int teste = 0;

	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0) {
		scanf("%d", &n);
		for (i = 0, cairam = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			if (x >= x1 && x <= x2 && y <= y1 && y >= y2) cairam++;
		}
		
		printf("Teste %d\n%d\n\n", ++teste, cairam);
	}

	return 0;
}
