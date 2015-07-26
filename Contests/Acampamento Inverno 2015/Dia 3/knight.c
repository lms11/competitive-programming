#include <stdio.h>

int abs(int a) { return a<0?-a:a; }

int main() {
	char a,b,c,d;

	while(scanf(" %c%c %c%c", &a,&b,&c,&d) != EOF) {
		printf("To get from %c%c to %c%c takes %d knight moves.\n", a,b,c,d, abs((int)(a-c)) + abs((int)(d-b)));
	}

	return 0;
}