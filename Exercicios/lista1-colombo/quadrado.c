#include <stdio.h>

int main() {
	int num;

	while(scanf("%d", &num) != EOF) {
		printf("%d\n", num * num);
	}

	return 0;
}
