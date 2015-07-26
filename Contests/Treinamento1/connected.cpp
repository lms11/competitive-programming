/* Problema: https://www.urionlinejudge.com.br/judge/en/problems/view/1082 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500

bool comp(int i, int j) { return (i > j); }

void dfs(vector<int> graph[], int visited[], int node) {
	visited[node] = 1;
	sort(graph[node].begin(), graph[node].end(), comp);

	printf("%c,", (char)node);

	while(graph[node].empty() == false) {
		if (visited[graph[node].back()] == 0) dfs(graph, visited, graph[node].back());
		graph[node].pop_back();
	}
}

int main() {
	int nt, t, n, m, c, d;
	char a, b;
	vector <int> graph[MAX];
	int visited[MAX];

	scanf("%d", &nt);

	for (t = 1; t <= nt; t++) {
		scanf("%d %d", &n, &m);

		for (c = 0; c < MAX; c++) visited[c] = 0;

		for(c = 0; c < m; c++) {
			scanf(" %c %c", &a, &b);
	
			graph[(int)a].push_back((int)b);
			graph[(int)b].push_back((int)a);
		}

		printf("Case #%d:\n", t);

		for (c = (int)'a', d = 0; c < ((int)'a' + n); c++) {
			if (visited[c] == 0) {
				d++;
				dfs(graph, visited, c);
				printf("\n");
			}
		}

		printf("%d connected components\n\n", d);
	}

	return 0;
}
