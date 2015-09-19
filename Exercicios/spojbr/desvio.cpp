#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define NODES 260
#define EDGES 33670

typedef pair<int, int> pii;

vector<pii > graph[NODES];
int n, m, c, k;
int dist[NODES];

int abs(int a) {
	return a < 0 ? -a : a;
}

void visit(priority_queue<pii, vector<pii >, greater<pii > > *pq, pii x) {
	int u = x.second;

	//printf("[CHECKING] Checking pair(%d, %d). There are %d items\n", x.first, x.second, graph[u].size());

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i].second, weight = graph[u][i].first;
		//printf("Trying to push: %d-%d %d --- %d > %d + %d\n", u, v, weight, dist[v], dist[u], weight);
		if (dist[v] > (dist[u] + weight)) {
			dist[v] = dist[u] + weight;
			//printf("Pushing: %d-%d %d\n", u, v, dist[v]);
			pq->push(pii(dist[v], v));
		}
	}
}

int dijkstra() {
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	for (int x = 0; x < NODES; x++) dist[x] = 2000000000;
	dist[k] = 0;
	visit(&pq, pii(0, k));

	while(!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		//printf("Cur: %d (%d) --- %d\n",  cur.second, dist[cur.second], cur.first);

		visit(&pq, cur);
	}

	return dist[c-1];
}

int main() {
	int a, b, d;

	while(scanf("%d %d %d %d", &n, &m, &c, &k)) {
		if (n == 0 || m == 0 || c == 0 || k == 0) break;
		//printf("N: %d || M: %d || C: %d || K: %d\n\n", n, m, c, k);

		while(m--) {
			scanf("%d %d %d", &a, &b, &d);

			if ((a < c && b < c) || (a >= c && b >= c)) {
				if (abs(a - b) > 1 && (a < c && b < c)) continue;
				graph[a].push_back(pii(d, b));
				graph[b].push_back(pii(d, a));

			} else if (b < c) {
				graph[a].push_back(pii(d, b));

			} else {
				graph[b].push_back(pii(d, a));

			}
		}

		printf("%d\n", dijkstra());
		for(int x = 0; x < NODES; x++) graph[x].clear();
	}

	return 0;
}
