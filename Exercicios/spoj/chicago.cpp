#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 110

typedef pair< double, int > pdi;

double distTo[NODES];
vector< pdi > graph[NODES];
priority_queue< pdi, vector< pdi >, less< pdi > > pq;

double dijkstra(int start, int end) {
	for(int x = 0; x < NODES; x++) {
		distTo[x] = 0.0;
	}
	distTo[start] = 100.0;
	
	pq.push(pdi(distTo[start], start));

	while(!pq.empty()) {
		double weight = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		vector<pdi >::iterator it;

		if (u == end) return distTo[u];		
		if (distTo[u] > weight) continue;

		for (it = graph[u].begin(); it != graph[u].end(); it++) {
			int v = it->second;
			double w = it->first;

			//printf("distTo[%d] < (distTo[%d] * %lf)/100 === %lf < (%lf * %lf)/100\n", v, u, w, distTo[v], distTo[u], w);
			if (distTo[v] < (distTo[u] * w) / 100.0) {
				distTo[v] = (distTo[u] * w) / 100.0;
				pq.push(pdi(distTo[v], v));
			}
		}
	}

	return distTo[end];
}

int main() {
	int n, q;
	int u, v, w;

	while (scanf("%d", &n), n != 0) {
		scanf("%d", &q);

		while(!pq.empty()) pq.pop();
		for (int x = 1; x <= n; x++) graph[x].clear();

		while(q--) {
			scanf("%d %d %d", &u, &v, &w);

			graph[u].push_back(pdi(w, v));
			graph[v].push_back(pdi(w, u));
		}

		printf("%.6f percent\n", dijkstra(1, n));
	}
	
	return 0;
}
