#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 1100

typedef pair<int, int> pii;

vector<pii > graph[NODES];
int dist[NODES];
int n, m;

void add(priority_queue<pii, vector<pii >, greater<pii > > *pq, int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int u = graph[x][i].second, weight = graph[x][i].first;

		if (dist[u] > dist[x] + weight) {
			dist[u] = dist[x] + weight;
			pq->push(pii(dist[u], u));
		}
	}
}

int dijkstra() {
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	
	for (int x = 0; x < NODES; x++) dist[x] = 2000000000;

	dist[0] = 0;
	add(&pq, 0);

	while(!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (cur.second == n+1) return dist[cur.second];

		add(&pq, cur.second);
	}

	return dist[n+1];
}

int main() {
	int a, b, c;
	scanf("%d %d", &n, &m);

	while(m--) {
		scanf("%d %d %d", &a, &b, &c);
		
		graph[a].push_back(pii(c, b));
		graph[b].push_back(pii(c, a));
	}

	printf("%d", dijkstra());

	return 0;
}
