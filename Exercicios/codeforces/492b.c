/* Problem: http://codeforces.com/problemset/problem/492/B */

#include <stdio.h>
#include <stdlib.h>

int v[10000];

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main() {
	int n, l, i;
	double d = 0.0;

	scanf("%d %d", &n, &l);

	for(i = 0; i < n; i++) scanf("%d", &v[i]);

	qsort(v, n, sizeof(int), compare);

	if (v[0] > 0)
		d = v[0];
    
    if (1.0 * (l - v[n-1]) > d)
    	d = l - v[n-1];

	for (i = 1; i < n; i++) {
		//printf("Diff between %d and %d: %.1f\n", v[i], v[i-1], 1.0 * (v[i] - v[i-1]) / 2);

		if ((1.0 * (v[i] - v[i-1]) / 2) > d)
			d = (1.0 * (v[i] - v[i-1]) / 2);

	}

	printf("%.10f", d);

	return 0;
}
