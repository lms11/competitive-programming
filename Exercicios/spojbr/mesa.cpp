#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 200

vector<int> graph[MAX];
int color[MAX];
bool visited[MAX];
int n, m;

bool bfs(int node) {
	queue<int> q;
	int cur;

	q.push(node);
	color[node] = 1;
	visited[node] = true;

	while(!q.empty()) {
		cur = q.front();
		q.pop();

		for (int u : graph[cur]) {
			if (visited[u] == 0) {
				color[u] = 3 - color[cur];
				visited[u] = true;
				q.push(u);

			} else if (color[u] == color[cur])
				return false;
		}
	}

	return true;
}

int main() {
	int a, b, t;
	bool ans;

	t = 1;

	while(scanf("%d %d", &n, &m) != EOF) {
		while(m--) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		printf("Instancia %d\n", t++);

		ans = true;

		for (a = 1; a <= n && ans; a++) {
			if (visited[a]) continue;
			ans = bfs(a);
		}

		if (ans) printf("sim\n\n");
		else printf("nao\n\n");

		for (a = 0; a < MAX; a++) {
			graph[a].clear();
			color[a] = 0;
			visited[a] = false;
		} 
	}

	return 0;
}