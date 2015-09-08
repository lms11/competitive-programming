#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 1100
#define EDGES 2000100

struct Edge {
	int v, w, weight;
	bool operator < (const Edge& e) const {
		return weight > e.weight;
	}
};

bool visited[NODES];
vector<Edge *> graph[NODES];
Edge edges[EDGES];

int one(Edge e) { return e.v; }
int another(Edge e, int v) { return e.v == v ? e.w : e.v; }

void visit(priority_queue<Edge> *pq, int x) {
	if (!visited[x]) {
		visited[x] = true;

		vector<Edge *>::iterator it;
		for (it = graph[x].begin(); it != graph[x].end(); it++) {
			if (!visited[another(**it, x)])
				pq->push(**it);
		}
	}
}

int mst(int s) {
	priority_queue<Edge> pq;
	int res = 0;

	visit(&pq, s);

	while(!pq.empty()) {
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
	int a, b, c, d, e;
	int t = 1, f = 0;

	while(scanf("%d %d", &a, &b) != EOF) {
		while(b--) {
			scanf("%d %d %d", &c, &d, &e);

			Edge *ed = &edges[f++];

			ed->v = c;
			ed->w = d;
			ed->weight = e;

			graph[c].push_back(ed);
			graph[d].push_back(ed);
		}
		int res = 0;
		for (int x = 1; x <= a; x++)
			res += mst(x);

		printf("Instancia %d\n%d\n\n", t++, res);

		f = 0;	
		for (int x = 0; x <= a; x++) {
			visited[x] = false;
			graph[x].clear();
		}
	}

	return 0;
}
