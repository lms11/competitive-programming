/* Problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1225 */

#include <stdio.h>

int bsearch(int *v, int start, int end, int key) {
	int mid = (start + end) / 2;
	while(start <= end) {
		if (v[mid] == key) return mid;
		else if (v[mid] < key) return bsearch(v, mid + 1, end, key);
		else if (v[mid] > key) return bsearch(v, start, mid - 1, key);
		else if (v[mid] != key && start == end) return start;
	}

	return start;
}

int main() {
	int n, i, index;
	long long int sum, average, result;
	int nums[10000];

	scanf("%d", &n);

	sum = 0;
	for(i = 0, index = 0; i < n; i++) {
		scanf("%d", &nums[i]);
		sum += nums[i];
	}

	average = sum / n;
	index = bsearch(nums, 0, n-1, average);

	average = average < 0 ? -average : average;

	for(result = 1; index < n; index++) result += nums[index] - average;
	
	if (sum % n == 0) printf("%lld", result);
	else printf("-1");

	return 0;
}
