#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 110

void dfs(vector <int> graph[], int visited[], int node) {
	visited[node] = 1;

	while(graph[node].empty() == false) {
		if (visited[graph[node].back()] == 0) dfs(graph, visited, graph[node].back());
		graph[node].pop_back();
	}
}

int main() {
	int t = 1, a, b, c, n, m;
	vector <int> graph[MAX];
	int visited[MAX];

	while (scanf("%d %d", &n, &m), n != 0 && m != 0) {
		for (c = 0; c <= n; c++) visited[c] = 0;

		for (c = m; c > 0; c--) {
			scanf("%d %d", &a, &b);

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (a = 0, b = 1; b <= n; b++) {
			if (visited[b] == 0) {
				dfs(graph, visited, b);
				a++;
			}
		}
		
		printf("Teste %d\n", t++);
		if (a > 1) printf("falha\n");
		else printf("normal\n");
	}

	return 0;
}
