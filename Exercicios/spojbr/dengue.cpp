#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int dist[105][105];
vector<int> graph[105];
bool visited[105];
long long int max_dist;
int max_dist_i;

void bfs(int start) {
	queue<int> q;
	q.push(start);

	memset(visited, false, sizeof(visited));
	visited[start] = true;
	dist[start][start] = 0;
	int tmp_max_dist = 0;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int x = 0; x < graph[cur].size(); x++) {
			int y = graph[cur][x];
			if (visited[y]) continue;

			dist[start][y] = dist[start][cur] + 1;
			if (tmp_max_dist < dist[start][y]) {
				tmp_max_dist = dist[start][y];
			}

			visited[y] = true;
			q.push(y);
		}
	}

	if (tmp_max_dist < max_dist) {
		max_dist = tmp_max_dist;
		max_dist_i = start;
	}
}

int main() {
	int t = 1;
	int n, a, b;

	while (scanf("%d", &n), n != 0) {
		max_dist = 2000000000;
		max_dist_i = -1;

		for (int x = 1; x < n; x++) {
			scanf("%d %d", &a, &b);

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int x = 1; x <= n; x++) bfs(x);

		printf("Teste %d\n%d\n\n", t++, max_dist_i);

		for (int x = 0; x < 105; x++) graph[x].clear();
	}

	return 0;
}
