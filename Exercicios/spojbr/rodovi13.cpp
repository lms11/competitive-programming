#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 11000

bool dfs(vector<int> graph[], int visited[], int node, int call) {
	if (visited[node] == 0 || visited[node] == 1) visited[node]++;
	else return false; /* Visitado 2 vezes => para o ciclo */

	bool response = true;

//	for(int x = 0; x < call; x++) printf("  ");
//	printf("(%d) Nó visitado: %d\n", visited[node], node);

	while(response && !graph[node].empty()) {
		response = dfs(graph, visited, graph[node].back(), call+1);
		graph[node].pop_back();
	}

	return response;
}

int main() {
	int t, n, a, b;
	vector<int> graph[MAX];
	int visited[MAX];
	bool worked = true;

	scanf("%d", &n);

	for(t = 0; t < MAX; t++) visited[t] = 0;

	t = n;
	while(t--) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	dfs(graph, visited, 1, 0);
	for(t = 1; t <= n; t++) worked = worked && (visited[t] == 2);

	if (worked) printf("S\n");
	else printf("N\n");

	return 0;
}
