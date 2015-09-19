#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define NODES 6000

map<string, int> mapa;
vector<int> graph[NODES];
bool vis[NODES];

int bfs(int start) {
	queue<int> q;
	int count = 0;

	vis[start] = 1;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		count++;

		for (int y = 0; y < graph[cur].size(); y++) {
			if (!vis[graph[cur][y]]) {
				vis[graph[cur][y]] = true;
				q.push(graph[cur][y]);
			}
		}
	}

	return count;
}

int main() {
	int n, m, b, max;
	string a, c;

	while(scanf("%d %d", &n, &m), n != 0) {
		b = 0;
		max = 0;

		for (int x = 0; x < n; x++) {
			cin >> a;
			mapa[a] = b++;
			vis[x] = false;
		}

		while(m--) {
			int u, v;
			cin >> a;
			cin >> c;
			u = mapa[a];
			v = mapa[c];

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int x = 0; x < n; x++) {
			if (vis[x]) continue;
			
			int res = bfs(x);
			if (res > max) max = res;
		}

		printf("%d\n", max);

		mapa.clear();
		for (int x = 0; x < NODES; x++) graph[x].clear();
	}

	return 0;
}
