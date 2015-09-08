#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 700

struct Edge {
	int v, w, weight;
	bool operator < (const Edge& e) const {
		return weight > e.weight;
	}
};

Edge edges[125000];
vector<Edge *> graph[MAX];
bool visited[MAX];

int one(Edge e) {
	return e.v;
}

int another(Edge e, int v) {
	if (e.v == v) return e.w;
	else return e.v;
}

void visit(priority_queue<Edge> *pq, int x) {
	if (visited[x] == false) {
		visited[x] = true;
		vector<Edge *>::iterator it;

		for (it = graph[x].begin(); it != graph[x].end(); it++) {
			if (visited[another(**it, x)] == false)
				pq->push(**it);
		}
	}
}

int mst() {
	priority_queue<Edge> pq;
	int res = 0;
	visit(&pq, 1);
	
	while(!pq.empty()) {
		Edge e = pq.top();
		pq.pop();

		int v = one(e), w = another(e, v);
		if (visited[v] && visited[w]) continue;
		res += e.weight;
		if (!visited[v]) visit(&pq, v);
		if (!visited[w]) visit(&pq, w); 
	}


	return res;
}

int main() {
	int n, m;
	int a, b, c;
	int t = 0;

	scanf("%d %d", &n, &m);

	while(m--) {
		scanf("%d %d %d", &a, &b, &c);
		visited[a] = visited[b] = false;
		
		Edge *e = &edges[t++];
		e->v = a;
		e->w = b;
		e->weight = c;

		graph[a].push_back(e);
		graph[b].push_back(e);
	}

	printf("%d\n", mst());

	return 0;
}


