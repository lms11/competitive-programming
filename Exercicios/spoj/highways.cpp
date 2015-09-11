#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 110000
#define MAX_TIME 1500000000 // exercise tell us the max time is 1000

typedef pair< int, int > ppi;

int dist[NODES];
vector< ppi > graph[NODES];

int dijkstra(int start, int end, int nodes) {
	priority_queue< ppi, vector< ppi >, greater< ppi > > pq;

	for (int x = 1; x <= nodes; x++) dist[x] = MAX_TIME;

	dist[start] = 0;
	pq.push(ppi(dist[start], start));

	while(!pq.empty()) {
		int a = pq.top().first;
		int b = pq.top().second;
		pq.pop();

		if (dist[b] < a) continue;
		if (b == end) return dist[b];

		for (int x = 0; x < graph[b].size(); x++) {
			int weight = graph[b][x].first;
			int c = graph[b][x].second;

			if (dist[c] > dist[b] + weight) {
				dist[c] = dist[b] + weight;
				pq.push(ppi(dist[c], c));
			}
		}

	}

	return MAX_TIME;
}

int main() {
	int t, n, q, start, end, a, b, c;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d %d", &n, &q, &start, &end);
	
		while(q--) {
			scanf("%d %d %d", &a, &b, &c);

			graph[a].push_back(ppi(c, b));
			graph[b].push_back(ppi(c, a));
		}

		int dist = dijkstra(start, end, n);
		if (dist == MAX_TIME) printf("NONE\n");
		else printf("%d\n", dist);

		for (int x = 0; x <= n; x++) graph[x].clear();
	}

	return 0;
}
