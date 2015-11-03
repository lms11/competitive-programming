#include <cstdio>
#include <vector>
using namespace std;

#define NODES 1010
#define EDGES 2010
#define INF 1e9

struct Edge {
	int u, v, weight;
};

int dist[NODES];
Edge edges[EDGES];

void reset() {
	for (int i = 0; i < NODES; i++) {
		dist[i] = INF;
	}
}

bool relax(Edge e) {
	if (dist[e.v] > dist[e.u] + e.weight) {
		dist[e.v] = dist[e.u] + e.weight;
		return true;
	}
	return false;
}

int main() {
	int N, E, t, k, i, j;
	bool ans;
	scanf("%d", &t);

	while(t--) {
		k = 0;
		scanf("%d %d", &N, &E);

		for (i = 0; i < E; i++) {
			Edge *e = &edges[k++];
			scanf("%d %d %d", &e->u, &e->v, &e->weight);
		}

		reset();

		for (i = 0; i < N-1; i++) {
			for (j = 0; j < k; j++)
				relax(edges[j]);
		}

		ans = false;

		for (j = 0; j < k; j++)
			ans = relax(edges[j]) || ans;

		if (ans) printf("possible\n");
		else printf("not possible\n");
	}

	return 0;
}