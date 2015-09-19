#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define NODES 1100
#define EDGES 510000

struct Edge {
	int u, v;
	double dist;
	bool operator < (const Edge& e) const {
		return dist > e.dist;
	}
};

int n;
vector<pair<double, double> > nodes;
vector<Edge *> graph[NODES];
Edge edges[EDGES];
bool visited[NODES];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void visit(priority_queue<Edge> *pq, int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		pq->push(*graph[x][i]);
	}
}

double prim() {
	double max = 0;
	priority_queue<Edge> pq;
	for (int x = 0; x< NODES; x++) visited[x] = false;

	visit(&pq, 0);

	while (!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();

		if (visited[cur.u] && visited[cur.v]) continue;

		if (max < cur.dist) max = cur.dist;

		if (!visited[cur.u]) visit(&pq, cur.u);
		if (!visited[cur.v]) visit(&pq, cur.v);
	}

	return max;
}

int main() {
	double a, b, c;
	Edge *cur;

	while (scanf("%d", &n), n != 0) {
		cur = edges;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &a, &b);
			nodes.push_back(make_pair(a, b));

			for (int j = 0; j < i; j++) {
				c = dist(a, b, nodes[j].first, nodes[j].second);
				cur->u = i;
				cur->v = j;
				cur->dist = c;				

				graph[i].push_back(cur);
				graph[j].push_back(cur);
				cur++;
			}
		}

		printf("%.4lf\n", prim());

		for (int x = 0; x < NODES; x++) graph[x].clear();
		nodes.clear();
	}

	return 0;
}
