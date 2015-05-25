#include <stdio.h>

void print_n(int a, int saida) {
	printf("Teste %d\n", saida);
	
	printf("%d ", a / 50);
	a %= 50;

	printf("%d ", a / 10);
	a %= 10;

	printf("%d ", a / 5);
	a %= 5;

	printf("%d\n\n", a);
}

int main() {
	int a, b = 0;
	int n[1000000];

	while(scanf("%d", &a), a != 0)
		n[b++] = a;

	for(a = 0; a < b; a++)
		print_n(n[a], a+1);

	return 0;
}
