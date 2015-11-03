#include <cstdio>
#include <queue>
using namespace std;

#define GRID 	35
#define INF		1e9
#define DEBUG	0

struct Edge {
	int x1, x2, y1, y2, t;
};

int W, H, K;
int rocks[GRID][GRID];
int dist[GRID][GRID];
Edge edges[4*GRID*GRID];


void printmatrix(int matrix[][GRID]) {
	for (int i = 0; i < H; i++, printf("\n"))
		for (int j = 0; j < W; j++)
			printf("%10d ", matrix[j][i]);

	printf("\n");
}

bool valid(int i, int j) { return i >= 0 && i < W && j >= 0 && j < H; }

void createGridEdge(int x, int y, int x2, int y2) {
	// printf("Criando: (%d, %d) ~ %d ~> (%d, %d)... ", x, y, 1, x2, y2);

	if (valid(x2, y2) && rocks[x2][y2] != 1) {
		// printf("Criado!\n");
		Edge *e = &edges[K++];
		e->x1 = x;
		e->y1 = y;
		e->x2 = x2;
		e->y2 = y2;
		e->t = 1;

	}
}


int main() {
	int G, x, y;
	bool ans;

	while(scanf("%d %d", &W, &H), W != 0 && H != 0) {
		// Reseting
		K = 0;
		for (x = 0; x < W; x++) {
			for (y = 0; y < H; y++) {
				rocks[x][y] = 0;
				dist[x][y] = INF;
			}
		}
		dist[0][0] = 0;

		// Getting rocks
		scanf("%d", &G);
		while(G--) {
			scanf("%d %d", &x, &y);
			rocks[x][y] = 1;
		}

		// Getting holes & creating the edges
		scanf("%d", &G);
		while(G--) {
			Edge *e = &edges[K++];
			scanf("%d %d %d %d %d", &e->x1, &e->y1, &e->x2, &e->y2, &e->t);
			rocks[e->x1][e->y1] = 2;
		}


		// Creating the grid's edges
		for (x = 0; x < W; x++) {
			for (y = 0; y < H; y++) {
				if (rocks[x][y] != 0 || (x == W-1 && y == H-1)) continue;

				createGridEdge(x, y, x + 1, y);
				createGridEdge(x, y, x - 1, y);
				createGridEdge(x, y, x, y + 1);
				createGridEdge(x, y, x, y - 1);
			}
		}

		if (DEBUG) {
			printmatrix(dist);
			printmatrix(rocks);
		}

		// Bellman Ford algorithm
		ans = false;
		for (x = 0; x < W*H; x++) {
			for (y = 0; y < K; y++) {
				Edge *e = &edges[y];

				if (DEBUG) {
					if (x == 0)
						printf("Edge: (%d, %d) ~ %d ~> (%d, %d)\n", e->x1, e->y1, e->t, e->x2, e->y2);
				}
	
				if (dist[e->x1][e->y1] == INF) continue;

				if (dist[e->x2][e->y2] > dist[e->x1][e->y1] + e->t) {
					dist[e->x2][e->y2] = dist[e->x1][e->y1] + e->t;
					ans = true;
				}
			}
		}

		if (DEBUG) {
			printmatrix(dist);
			printmatrix(rocks);
		}

		if (ans) {
			ans = false;
			for (y = 0; y < K; y++) {
				Edge *e = &edges[y];

				if (dist[e->x1][e->y1] == INF) continue;

				if (dist[e->x2][e->y2] > dist[e->x1][e->y1] + e->t) {
					dist[e->x2][e->y2] = dist[e->x1][e->y1] + e->t;
					ans = true;
				}
			}

			if (ans) printf("Never\n");
			else if (dist[W-1][H-1] == INF) printf("Impossible\n");
			else printf("%d\n", dist[W-1][H-1]);
			
		} else if (dist[W-1][H-1] == INF) printf("Impossible\n");
		else printf("%d\n", dist[W-1][H-1]);
	}

	return 0;
}