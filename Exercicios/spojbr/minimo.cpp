#include <cstdio>
#include <queue>
#include <vector>

#define INF		1000000000
#define NODES 	106

int dist[NODES][NODES][NODES+1];

int min(int a, int b) { return a < b ? a : b; }

void floyd_marshall(int nodes) {
	for (int k = 0; k < nodes; k++) {
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				dist[i][j][k+1] = min(dist[i][j][k], dist[i][k][k] + dist[k][j][k]);
			}
		}
	}
}

int main() {
	int n, m, a, b, c, t = 1;

	while(scanf("%d %d", &n, &m) != EOF) {
		for (int x = 0; x < NODES; x++) 
			for (int y = 0; y < NODES; y++) 
				for (int z = 0; z < NODES; z++)
					if (y == z) dist[y][z][x] = 0;
					else dist[y][z][x] = INF;


		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			dist[a][b][0] = c;
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
