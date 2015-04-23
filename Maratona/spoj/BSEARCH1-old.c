#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
	long long int value, position;
} Pair;

int compare(const void * a, const void * b) {
	long long int val_a = ((const Pair *)a)->value;
	long long int val_b = ((const Pair *)b)->value;
	return (val_a < val_b) ? -1 : (val_a > val_b);
}

int bSearchCompare(const void * a, const void * b) {
	// a => key, b => element
	long long int val_a = *(long long int *)a;
	long long int val_b = ((const Pair *)b)->value;

	return (val_a < val_b) ? -1 : (val_a > val_b) ? 1 : 0;
}

int main() {
	long long int n, q, i, tmp;
	Pair * object;

	scanf("%lld %lld", &n, &q);

	Pair values[100000];
	long long int queries[500000];

	for (i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		if (tmp > 1000000000 || tmp < -1000000000) return 0;

		values[i].value = tmp;
		values[i].position = i; 
	}

	qsort(values, n, sizeof(Pair), compare);

	for (i = 0; i < q; i++) {
		scanf("%lld", &queries[i]);
		if (queries[i] > 1000000000 || queries[i] < -1000000000) return 0;
	}

	for (i = 0; i < q; i++) {
		// looking for queries[z]
		object = (Pair *) bsearch(&queries[i], values, n, sizeof(Pair), bSearchCompare);

		if (object == NULL) printf("-1\n");
		else printf("%lld\n", object->position);
	}

	return 0;
}
