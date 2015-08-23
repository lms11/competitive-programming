#include <stdio.h>

int max(int a, int b)	{ return a > b ? a : b; }
int abs(int a)		{ return a < 0 ? -a : a; }

int main() {
	int a, b, t, m, n;

	while(scanf("%d %d %d", &t, &a, &b) != EOF) {
		m = 1;
		n = 0;

		while(abs((m * a) - (n * b)) % t != 0) {
			n++;
			if (abs((m * a) - (n * b)) % t == 0) break;
			m++;
		}

		printf("%d\n", max(m*a, n*b));
	}	

	return 0;
}
