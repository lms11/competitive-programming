#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 700

vector< pair<int, int> > graph[NODES];
bool visited[NODES];
queue<int> q;

long long int mst(int n) {
	long long int sum = 0;
	int min;

	for (int x = 0; x < NODES; x++)
		visited[x] = false;

	q.push(n);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		if (visited[node]) continue;

		visited[node] = true;
		min = -1;

		for (vector< pair<int, int> >::iterator it = graph[node].begin(); it != graph[node].end(); it++) {
			if (!visited[it->first]) {
				q.push(it->first);

				if (it->second < min || min == -1) {
					min = it->second;
				}
			}
		}

		if (min >= 0) sum += min;
	}

	return sum;
}

int main() {
	int a, b, c, d, e;

	scanf("%d %d", &a, &b);

	while(b--) {
		scanf("%d %d %d", &c, &d, &e);
	
		graph[c].push_back(make_pair(d, e));
		graph[d].push_back(make_pair(c, e));
	}

	long long int sum = 0;

	for (int x = 1; x <= a; x++) {
		if (!visited[x])
			sum += mst(x);
	}

	printf("%lld\n", sum);

	return 0;
}