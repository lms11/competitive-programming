#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int notas[] = { 100, 50, 20, 10, 5, 2, 1 }, n_notas[] = { 0, 0, 0, 0, 0, 0, 0 };
	int valor, cur_nota;

	scanf("%d", &valor);

	if (valor > 0 && valor < 1000000) {
		printf("%d\n", valor);
		for (int i = 0; i < 7; i++) {
			cur_nota = notas[i];
			n_notas[i] = valor / cur_nota;
			valor = valor % cur_nota;

			printf("%d nota(s) de R$ %d,00\n", n_notas[i], cur_nota);
		}
	}
    return 0;
}

// erro de compilação ??