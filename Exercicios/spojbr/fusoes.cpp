#include <cstdio>

#define MAX 100000

int cod[MAX];
int siz[MAX];

int find(int n) {
	while(cod[n] != n) n = cod[n];
	return n;
}

void un(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (siz[a] > siz[b]) {
		cod[b] = a;
		siz[a] += siz[b];

	} else {
		cod[a] = b;
		siz[b] += siz[a];

	}
}

int main() {
	int a, b, x, c, d;
	char e;

	scanf("%d %d", &a, &b);

	for (x = 1; x <= a; x++) {
		cod[x] = x;
		siz[x] = 1;
	}


	for (x = 0; x < b;  x++) {
		scanf(" %c %d %d", &e, &c, &d);

		if (e == 'F') {
			un(c, d);

		} else {
			if(find(c) == find(d)) printf("S\n");
			else printf("N\n");

		}
	}

	return 0;
}
