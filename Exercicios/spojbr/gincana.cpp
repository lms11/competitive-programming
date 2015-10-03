#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 1100


void dfs(vector <int> graph[], int visited[], int node) {
	visited[node] = 1;

	while(graph[node].empty() == false) {
		if (visited[graph[node].back()] == 0) dfs(graph, visited, graph[node].back());
		graph[node].pop_back();
	}
}

int main() {
	int m, n, a, b, c;
	int visited[MAX];
	vector <int> graph[MAX];

	scanf("%d %d", &n, &m);

	c = m;

	while(c--) {
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (b = 0; b <= n; b++) visited[b] = 0;

	for (c = 1, b = 0; c <= n; c++) {
		if (visited[c] == 0) {
			b++;
			dfs(graph, visited, c);
		}
	}

	printf("%d\n", b);

	return 0;
}
