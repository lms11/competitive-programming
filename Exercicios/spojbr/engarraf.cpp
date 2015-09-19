#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define NODES 400
#define EDGES 40000

typedef pair<int, int> pii;

int n, m;
vector<pii > graph[NODES];
int dist[NODES];

void visit(priority_queue<pii, vector<pii>, greater<pii> > *pq, pii x) {
	int u = x.second;

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i].second, weight = graph[u][i].first;

		if (dist[v] > dist[u] + weight) {
			dist[v] = dist[u] + weight;
			pq->push(pii(dist[v], v));
		}
	}
}

int dijkstra(int start, int target) {
	if (start == target) return 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int x = 0; x < NODES; x++) dist[x] = 2000000000;
	dist[start] = 0;

	visit(&pq, pii(0, start));

	while(!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (cur.second == target) return dist[target];

		visit(&pq, cur);
	}

	if (dist[target] == 2000000000) return -1;
	else return dist[target];
}

int main() {
	int s, d, a, b, c;

	while(scanf("%d %d", &n, &m), n != 0) {
		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back(pii(c, b));
			//graph[b].push_back(pii(c, a));
		}

		scanf("%d %d", &s, &d);

		printf("%d\n", dijkstra(s, d));

		for (int x = 0; x < NODES; x++) graph[x].clear();
	}

	return 0;
}



