#include <cstdio>

#define INF		100000000
#define NODES 	105

int dist[NODES][NODES][NODES];

int min(int a, int b) { return a < b ? a : b; }

void floyd_marshall(int nodes) {
	int i, j, k;

	for (k = 1; k <= nodes; k++) {
		for (i = 1; i <= nodes; i++) {
			for (j = 1; j <= nodes; j++) {
				dist[i][j][k] = min(dist[i][j][k-1], dist[i][k][k-1] + dist[k][j][k-1]);
			}
		}
	}
}

int main() {
	int n, m, a, b, c, t = 1;

	while(scanf("%d %d", &n, &m) != EOF) {
		for (a = 0; a < NODES; a++) 
			for (b = 0; b < NODES; b++)
				for (c = 0; c < NODES; c++)
					if (a == b)
						dist[a][b][c] = 0;
					else
						dist[a][b][c] = INF;


		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			dist[a][b][0] = min(dist[a][b][0], c);
		}

		floyd_marshall(n);

		scanf("%d", &m);
		printf("Instancia %d\n", t++);

		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			
			if (dist[a][b][c] == INF) printf("-1\n");
			else printf("%d\n", dist[a][b][c]);
		}

		printf("\n");
	}

	return 0;
}
