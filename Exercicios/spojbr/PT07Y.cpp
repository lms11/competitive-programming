#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

/*
	IDEIA:
	Verificar se eu visitei um nó mais de uma vez.
	- Se sim, isso mostra que o grafo é ciclico e, logo, não é uma árvore.
	- Se não, temos que verificar se todo nó estão conectados entre si. Logo, se (número de nós - 1) == (número de vértices).
*/

#define MAX 10010

int dfs(vector<int> graph[], int visited[], int node) {
	int response = 1;

	if (visited[node] == 0) visited[node] = 1;
	else return 0;
	
	while(graph[node].empty() == false) {
		response = response == 0 ? 0 : dfs(graph, visited, graph[node].back());
		graph[node].pop_back();
	}

	return response;
}

int main() {
	int m, n, a, b, c;
	vector <int> graph[MAX];
	int visited[MAX];

	scanf("%d %d", &n, &m);

	c = m;

	while(c--) {
		scanf("%d %d", &a, &b);

		for (int i = 0; i < MAX; i++) visited[i] = 0;
		
		graph[a].push_back(b);
		// graph[b].push_back(a);
	}

	c = dfs(graph, visited, a);

	if (n-1 == m && c == 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}
