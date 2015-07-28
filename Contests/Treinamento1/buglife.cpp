#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAX 2200

bool dfs(vector<int> graph[], int sexo[], int node, int call) {
	if (sexo[node] == 0) sexo[node] = 1;

//	for(int x = 0; x < call; x++) printf("  ");
//	printf("Nó visitado: %d. Sexo: %d\n", node, sexo[node]);

	while(graph[node].empty() == false) {
		int n = graph[node].back();
		graph[node].pop_back();

		if (sexo[n] == 0) {
			if (sexo[node] == 1) sexo[n] = 2;
			else sexo[n] = 1;
				
//			for(int x = 0; x < call; x++) printf("  ");
//			printf("  Setando sexo do nó %d: %d", n, sexo[n]);
//			printf("\n");

		} else {
			if (sexo[n] == sexo[node])
				return false;
		}

		if (!dfs(graph, sexo, n, call+1)) return false;
		
	}

	return true;
}

int main() {
	int x, n, t, a, b, c, d;
	vector<int> graph[MAX];
	int sexo[MAX];
	bool worked;

	scanf("%d", &n);

	t = n;

	while(t--) {
		worked = true;

		scanf("%d %d", &a, &b);

		for(x = 1; x <= a; x++) sexo[x] = 0;

		for(x = 0; x < b; x++) {
			scanf("%d %d", &c, &d);
		
			graph[c].push_back(d);
			graph[d].push_back(c);
		}

		printf("Scenario #%d:\n", (n-t));

/*		for (x = 1; x <= a; x++) {
			printf("Nó: %d. Vertices com: ", x);
			vector<int>::iterator it;
			for(it = graph[x].begin(); it != graph[x].end(); it++) printf("%d, ", *it);
			printf("\n");
		}
*/

		for (x = 1; x <= a; x++) {
			if (sexo[x] == 0) {
				worked = dfs(graph, sexo, x, 0);

				if (worked == false) break;
			}
		}

		if (worked) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");

		for(x = 1; x <= a; x++) graph[x].clear();
	}
}
