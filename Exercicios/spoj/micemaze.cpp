#include <cstdio>
#include <vector>
using namespace std;

#define MAX 110
#define INF 1000000000

int E, N;
int dist[MAX][MAX];

void floyd_mashall() {
	int i, j, k;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main() {
	int t, m, a, b, c, i, j;

	scanf("%d %d %d %d", &N, &E, &t, &m);

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (i == j) dist[i][i] = 0;
			else dist[i][j] = INF;
		}
	}

	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}

	floyd_mashall();

	for (a = 1, b = 0; a <= N; a++) {
		if (t - dist[a][E] >= 0) {
			b++;
		}
	}

	printf("%d\n", b);


	return 0;
}