/* Problema: http://br.spoj.com/problems/FREQUE12/ */

#include "stdio.h"
#include "stdlib.h"

#define MAX 1500000

int main() {
	int n, i, sum, tmp;
	int nums[MAX];

	scanf("%d", &n);
	sum = 0;

	for (i = 0; i < n; i++) nums[tmp] = 0;

	for(i = 0; i < n; i++) {
		scanf("%d", &tmp);

		if (nums[tmp] == 0) {
			nums[tmp] = 1;
			sum++;
		}
	}

	printf("%d\n", sum);

	return 0;
}
