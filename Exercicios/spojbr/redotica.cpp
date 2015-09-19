#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 106
#define EDGES 6000

struct Edge {
	int v, w, weight;
	bool operator < (const Edge& e) const {
		return weight > e.weight;
	}
};

typedef pair<int, int> pii;

bool visited[NODES];
vector<Edge *> graph[NODES];
Edge edges[EDGES];


int another(Edge *e, int x) {
	return e->v == x ? e->w : e->v;
}

void visit(int x, priority_queue<Edge> *pq) {
	if (!visited[x]) {
		visited[x] = true;

		for (int k = 0; k < graph[x].size(); k++) {
			if (!visited[another(graph[x][k], x)]) {
				pq->push(*(graph[x][k]));
			}
		}
	}
}

vector<pii > prim(int start) {
	vector<pii > res;
	priority_queue<Edge> pq;

	visit(start, &pq);

	while(!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();

		if (visited[cur.v] && visited[cur.w]) continue;

		int x = cur.v < cur.w ? cur.v : cur.w;
		int y = another(&cur, x);
	
		res.push_back(pii(x, y));

		if (!visited[cur.v]) visit(cur.v, &pq);
		if (!visited[cur.w]) visit(cur.w, &pq);
	}

	return res;
}

void reset() {
	for (int x = 0; x < NODES; x++) {
		visited[x] = false;
		graph[x].clear();
	}
}

int main() {
	int n, q, i, t = 1;
	int a, b, c;

	while (scanf("%d %d", &n, &q), n != 0) {
		reset();
		i = 0;

		while(q--) {
			scanf("%d %d %d", &a, &b, &c);

			Edge *ed = &edges[i++];

			ed->v = a;
			ed->w = b;
			ed->weight = c;

			graph[a].push_back(ed);
			graph[b].push_back(ed);
		}

		printf("Teste %d\n", t++);
		for (int y = 1; y <= n; y++) {
			if (visited[y]) continue;

			vector<pii > res = prim(y);
		
			for (int x = 0; x < res.size(); x++)
				printf("%d %d\n", res[x].first, res[x].second);
		}

		printf("\n");
	}

	return 0;
}
