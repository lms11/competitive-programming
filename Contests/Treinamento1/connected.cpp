/* Problema: https://www.urionlinejudge.com.br/judge/en/problems/view/1082 */

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

#define MAX 500

void printset(set <int> myset) {
	set<int>::iterator it;
	for(it = myset.begin(); it != myset.end(); it++) {
		printf("%c,", *it);
	}
	printf("\n");
}

set<int> dfs(vector<int> graph[], int visited[], int node) {
	set <int> response;
	visited[node] = 1;

	response.insert(node);

	while(graph[node].empty() == false) {
		if (visited[graph[node].back()] == 0) {
			set<int> rec_response = dfs(graph, visited, graph[node].back());
			response.insert(rec_response.begin(), rec_response.end());
		}

		graph[node].pop_back();
	}

	return response;
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
				set<int> response = dfs(graph, visited, c);
				printset(response);
			}
		}

		printf("%d connected components\n\n", d);
	}

	return 0;
}
