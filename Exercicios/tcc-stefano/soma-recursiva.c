#include <stdio.h>

int soma(int v[], int start, int n) {
	int a = v[start];
	if (start == n-1) return v[start];
	else a += soma(v, start+1, n);

	return a;
}

int main() {
	int v[5] = { 1, 2, 3, 4, 5 };
	int s = soma(v, 0, 5);

	printf("Soma: %d\n", s);

	return s;
}
