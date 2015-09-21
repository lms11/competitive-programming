#include <cstdio>
using namespace std;

#define N 110

int dist[N][N];
int memo[N][N];
int w, h;

int max(int a, int b) {
	return a > b ? a : b;
}

int pd(int j, int i) {
	if (i < 0 || i >= w || j >= h) return 0;
	if (memo[j][i] != -1) return memo[j][i];

	return (memo[j][i] = dist[j][i] + max( pd(j+1, i-1), max(pd(j+1, i), pd(j+1, i+1)) ));
}

int main() {
	int n, a;

	scanf("%d", &n);

	while(n--) {
		scanf("%d %d", &h, &w);

		for(int x = 0; x < h; x++)
			for (int y = 0; y < w; y++) {
				scanf("%d", &dist[x][y]);
				memo[x][y] = -1;
			}

		int i = 0;
		for (int x = 0; x < w; x++)
			i = max(i, pd(0, x));

		printf("%d\n", i);
	}

	return 0;
}