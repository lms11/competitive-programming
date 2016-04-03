#include <cstdio>
#include <cstring>

int memo[1000010];

int pd(int n, int k) {
	if (n <= k) return 1;
	else if (memo[n] != -1) return memo[n];

	return memo[n] = pd(n/2, k) + pd((n+1)/2, k);
}

int main() {
	int n, k;

	while(scanf("%d %d", &n, &k), n != 0) {
		memset(memo, -1, sizeof memo);

		printf("%d\n", pd(n, k));
	}

	return 0;
}