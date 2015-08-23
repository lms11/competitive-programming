/* Problema: http://br.spoj.com/problems/PAPRIMAS/ */

#include <stdio.h>

int cton(char a) {
	int res = a - 96;
	if (res < 0) res += 58;
	return res;
}

void print(int a) {
	int b;
	for (b = 2; b < a; b++)
		if (a % b == 0) {
			printf("It is not a prime word.\n");
			return;
		}
	printf("It is a prime word.\n");
}

int main() {
	char in[21];
	int sum, i;

	while(scanf("%s", in) != EOF) {
		i = sum = 0;
		while(in[i] != 0) 
			sum += cton(in[i++]); 
	
		print(sum);
	}

	return 0;
}
