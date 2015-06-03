/* Problem: http://br.spoj.com/problems/BANFARAO/ */

#include <stdio.h>
#include <limits.h>

// Start/end => onde estou buscando. Left/right => o que/onde quero buscar
void update(long long int *tree, int interval, int start, int end, int index, int new_value) {
	int mid;
	long long int a, b;

	if (start == end) tree[index] = new_value;
	else if (start > right || end < left) return INT_MIN;
	else {
		mid = (start + end) / 2;
		
		if (interval <= mid) update(tree, interval, start, mid, index * 2, new_value);
		else update(tree, interval, mid+1, end, index * 2 + 1, new_value);

		a = search(... n*2);
		b = search(... n*2 + 1);
		
		if (a == INT_MIN) tree[index] = b;
		else if (b == INT_MIN) tree[index] = a;
		else tree[index] = a + b;
	}
}

long long int search(long long int *tree, 

int main() {
	int tree[400000];
	int t, n, q, l, r, i, tmp;
	scanf("%d", &t);

	while(t > 0) {
		scanf("%d", &n);

		for(i = 1; i <= n; i++) {
			scanf("%d", &tmp);

			update(tree, i, 1, n, 1, tmp);
		}

		printf("\nSEGTREE: \n");

		for(i = 0; i < 4*n+1; i++) printf("%lld ", tree[i]);

		/*scanf("%d", &q);
		
		for(i = 0; i < q; i++) {
			scanf("%d %d", &l, &r);

			printf("%lld %d\n", max.sum, max.end - max.begin + 1);
		}*/

		t--;
	}

	return 0;
}
