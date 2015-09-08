#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 300
#define EDGES 40000

struct Edge {
	int v, w, weight;
	bool operator < (const Edge& e) const {
		return weight > e.weight;
	}
};

bool visited[NODES];
vector<Edge *> graph[NODES];
Edge edges[EDGES];
int sites[NODES];
int k;


int one(Edge e) { return e.v; }
int another(Edge e, int v) { return e.v == v ? e.w : e.v; }

void visit(priority_queue<Edge> *pq, int x) {
	if (!visited[x]) {
		visited[x] = true;

		vector<Edge *>::iterator it;

		for(it = graph[x].begin(); it != graph[x].end(); it++) {
			if (!visited[another(**it, x)])
				pq->push(**it);
		}
	}
}

int mst() {
	priority_queue<Edge> pq;
	int res = 0;

	for (int x = 0; x < k; x++) visit(&pq, sites[x]);

	while (!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();

		int v = one(cur), w = another(cur, v);

		if (visited[v] && visited[w]) continue;

		res += cur.weight;

		if (!visited[v]) visit(&pq, v);
		if (!visited[w]) visit(&pq, w);
	}

	return res;
}

int main() {
	int n, m, t = 1, N;
	int a, b, c, f;

	scanf("%d", &N);

	for(; t <= N; t++) {
		scanf("%d %d %d", &n, &m, &k);
		f = 0;

		for(int x = 0; x < k; x++)
			scanf("%d", &sites[x]);
	
		while(m--) {
			scanf("%d %d %d", &a, &b, &c);

			Edge *ed = &edges[f++];

			ed->v = a;
			ed->w = b;
			ed->weight = c;

			graph[a].push_back(ed);
			graph[b].push_back(ed);			
		}

		printf("Case #%d: %d\n", t, mst());

		for(int x = 0; x <= n; x++) {
			visited[x] = false;
			graph[x].clear();
		}
	}


	return 0;
}
