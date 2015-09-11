#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 100

vector<int> graph[NODES];
bool visited[NODES];
int distTo[NODES];

priority_queue<int, vector<int>, greater<int> > bfs(int start, int maxDist) {
	priority_queue<int, vector<int>, greater<int> > result;
	queue<int> q;

	for (int x = 0; x < NODES; x++) {
		visited[x] = false;
//		distTo[x] = 0;
	}

	visited[start] = true;
	distTo[start] = 0;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur != start) result.push(cur);
		if (distTo[cur] < maxDist) {
			for (int x = 0; x < graph[cur].size(); x++) {
				int y = graph[cur][x];
				if (!visited[y]) {
					distTo[y] = distTo[cur] + 1;
					q.push(y);
					visited[y] = true;
				}
			}
		}
	}

	return result;
}

int main() {
	int c, e, l, p;
	int a, b;	
	int t = 1;


	while (scanf("%d %d %d %d", &c, &e, &l, &p), c != 0 && e != 0 && l != 0 && p != 0) {
		while(e--) {
			scanf("%d %d", &a, &b);
			
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		priority_queue<int, vector<int>, greater<int> > res = bfs(l, p);
		
		printf("Teste %d\n", t++);
		
		if (res.size() >= 1) {
			printf("%d", res.top());
			res.pop();

			while(!res.empty()) {
				printf(" %d", res.top());
				res.pop();
			}
		}

		printf("\n\n");

		for (int x = 0; x <= c; x++) graph[x].clear();
	}

	return 0;
}
