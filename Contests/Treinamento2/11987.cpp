#include <cstdio>
using namespace std;

#define OFFSET	100001
#define MAX 	2 * OFFSET + 10

int n, m, a, b, c;
int id[MAX], size[MAX];
long long int sum[MAX];

void debug() {
	printf("After command %d (with args: %d %d):\n", a, b, c);
	
	for(int x = 1; x <= n; x++) printf("%6d ", x);
	printf("\n");
	for(int x = 1; x <= n; x++) printf("%6d ", id[x]);
	printf("\n\n");
}

int find(int a) {
	if (a < OFFSET) a = id[a] = find(id[a]);
	return a;
}

void unify(int a, int b) {
	int root_a = find(a),
		root_b = find(b);

	if (root_a == root_b) return;

	if (size[root_a] < size[root_b]) {
		id[a] = id[root_a] = root_b;
		size[root_b] += size[root_a];
		sum[root_b] += sum[root_a];

	} else {
		id[b] = id[root_b] = root_a;
		size[root_a] += size[root_b];
		sum[root_a] += sum[root_b];

	}
}

void insert(int a, int b) {
	int root_a = find(a),
		root_b = find(b);

	if (root_a == root_b) return;

	id[a] = root_b;

	size[root_a] -= 1;
	sum[root_a] -= a;

	size[root_b] += 1;
	sum[root_b] += a;
}

int get_size(int a) {
	return size[find(a)];
}

long long int get_sum(int a) {
	return sum[find(a)];
}

int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		// Reset variables
		id[0] = -1;
		for (a = 1; a <= n; a++) {
			id[a]   = a + OFFSET;
			size[a+OFFSET] = 1;
			sum[a+OFFSET]  = a;
		}

		while(m--) {
			scanf("%d", &a);

			if (a == 1 || a == 2) {
				scanf("%d %d", &b, &c);

				if (a == 1) unify(b, c);
				else insert(b, c);

			} else if (a == 3) {
				scanf("%d", &b);

				b = find(b);
				printf("%d %lld\n", get_size(b), get_sum(b));
			}

//			debug();
		}

	}

	return 0;
}
