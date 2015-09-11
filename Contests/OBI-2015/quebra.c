#include <stdio.h>

#define MAX 210000

int next[MAX];
char c[MAX];

int main() {
	int n;
	int i, j;
	char k;

	scanf("%d", &n);

	while(n--) {
		scanf("%d %c %d", &i, &k, &j);
		
		next[i] = j;
		c[i] = k;
	}

	for (int x = 0; x != 1; x = next[x]) {
		printf("%c", c[x]);
	}

	return 0;
}
