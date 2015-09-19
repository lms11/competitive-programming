#include <cstdio>
#include <cstring>
using namespace std;

long long int soma;

void calculate(char *str, bool emQ, long long int custo) {
	if (str[0] == '\0') {
		if (emQ) soma += custo;	
		return;
	}

	if (str[0] == 'a') {
		if (!emQ) {
			calculate(str+1, false, custo);

		} else {
			calculate(str+1, true, custo * 2);
	
		}		

	} else {
		if (!emQ) {
			calculate(str+1, false, custo);
			calculate(str+1, true, custo);

		} else {
			calculate(str+1, true, custo * 2);

		}
	}
}

int main() {
	char input[70];
	int t = 1;

	while(scanf(" %s", input) != EOF) {
		soma = 0;
		calculate(input, false, 1);

		printf("Palavra %d\n%lld\n\n", t++, soma);

		memset(input, '\0', sizeof(input));
	}

	return 0;
}
