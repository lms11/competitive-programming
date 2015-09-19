#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define NODES 2100

typedef pair<int, int> pii; // vertex and connectivity. Connectivity: 0 not connected, 1: connected, 2: strongly connected (both directions)

vector<pii > graph[NODES];
bool visited[NODES];
int n, m;

void visit(stack<int> *s, int *count, int x, bool transposed) {
	if (visited[x]) return;

	(*count)++;
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		pii j = graph[x][i];

		if (!visited[j.first] && ((transposed && j.second != 1) || (!transposed && j.second != 0))) {
			s->push(j.first);
		}
	}
}


bool kosaraju(bool transposed) {
	stack<int> s;
	int count = 0;	

	for (int x = 0; x < NODES; x++)
		visited[x] = false;

	visit(&s, &count, 1, transposed);

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		visit(&s, &count, cur, transposed);
	}

	return count == n;
}

int main() {
	int v, w, p;

	while(scanf("%d %d", &n, &m), n != 0) {
		while(m--) {
			scanf("%d %d %d", &v, &w, &p);

			if (p == 2) {
				graph[v].push_back(pii(w, 2));
				graph[w].push_back(pii(v, 2));

			} else {
				graph[v].push_back(pii(w, 1));
				graph[w].push_back(pii(v, 0));
			}
		}

		bool res = kosaraju(false) && kosaraju(true);
		printf("%d\n", res);

		for (int x = 0; x < NODES; x++) graph[x].clear();
	}

	return 0;
}
