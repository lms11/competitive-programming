#include <cstdio>
#include <queue>
using namespace std;

#define MAX 10010

int bfs(vector<int> graph[], int visited[], int distance[], int node, int n) {
	queue<int> q;
	int max_dist = -1, max_dist_node = -1;
	int cur_node = -1, cnode2 = -1, i = 0;

	for (i = 0; i <= n; i++) {
		visited[i] = 0;
		distance[i] = -1;
	}

	q.push(node);
	distance[node] = 0;
	visited[node] = 1;	

	while(q.empty() == false) {
		cur_node = q.front();
		q.pop();

		for(i = 0; i < graph[cur_node].size(); i++) {
			cnode2 = graph[cur_node][i];
			
			if (visited[cnode2] == 0) {
				visited[cnode2] = 1;
				distance[cnode2] = distance[cur_node] + 1;			
				
				if (distance[cnode2] > max_dist) {
					max_dist = distance[cnode2];
					max_dist_node = cnode2;
				}

				q.push(cnode2);
			}
		}
	}

	return max_dist_node;
}

int main() {
	int n, a, b;
	vector<int> graph[MAX];
	int visited[MAX], distance[MAX];
	int result = -1;

	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	result = bfs(graph, visited, distance, 1, n);
	result = bfs(graph, visited, distance, result, n);

	printf("%d\n", distance[result]);

	return 0;
}
