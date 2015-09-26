#include <cstdio>
#include <cstring>

int memo[50][50]; // states: [position][number of open brackets]
int sqrbr[50];
int t, k, aux, n;

int pd(int i, int num) {
	if (i > n && num == 0) return 1;
	else if (i > n) return 0;
	else if (memo[i][num] != -1) return memo[i][num];

	int res = pd(i+1, num+1);

	if (!sqrbr[i] && num > 0) {
		res += pd(i+1, num-1);
	}

	return memo[i][num] = res;
}

int main() {
	scanf("%d", &t);

	while(t--) {
		memset(sqrbr, 0, sizeof sqrbr);
		memset(memo, -1, sizeof memo);

		scanf("%d %d", &n, &k);

		for(int x = 0; x < k; x++) {
			scanf("%d", &aux);
			sqrbr[aux] = 1;
		}

		n *= 2;

		printf("%d\n", pd(1, 0));
	}

	return 0;
}