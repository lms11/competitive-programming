#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int v[105], memo[110][110];
int n;
long long dist[105];

inline int sum(int i, int j) {
	long long res = dist[j] - dist[i-1];
	return res % 100;
}

int pd(int i, int j) {
	if (i >= j) return 0;
	else if (memo[i][j] != -1) return memo[i][j];

	int res = INT_MAX;

	for (int k = i; k < j; k++) {
		res = min(res, (sum(i, k) * sum(k+1, j)) + pd(i, k) + pd(k+1, j));
	}

	return memo[i][j] = res;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		long long sum = 0;

		memset(memo, -1, sizeof memo);

		for (int x = 0; x < n; x++) {
			scanf("%d", &v[x]);
			sum += v[x];
			dist[x] = sum;
		}

		printf("%d\n", pd(0, n-1));
	}

	return 0;
}