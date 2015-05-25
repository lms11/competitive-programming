#include <stdio.h>
#define MAX 50000

int bsearch(int v[], int start, int end, int key) {
	int mid = (start + end) / 2;
	
	if (start <= end) {
		if (v[mid] > key) return bsearch(v, start, mid - 1, key);
		else if (v[mid] < key) return bsearch(v, mid + 1, end, key);
		else if (v[mid] == key) return mid;
	}

	return -1;
}

int abs(int a) { return a < 0 ? -a : a; }

int main() {
	int m, n, i, prev_i, next_i, sum, val_m;
	int v_n[MAX];

	while(scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		prev_i = 1;
		next_i = sum = val_m = 0;

		for(i = 0; i < n; i++) {
			scanf("%d", &v_n[i]);
		}

		for(i = 0; i < m; i++) {
			scanf("%d", &val_m);
			next_i = bsearch(v_n, 0, n - 1, val_m) + 1;
			sum += abs(next_i - prev_i);
			prev_i = next_i;
		}

		printf("%d\n", sum);
	}

	return 0;
}
