#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define NODES 25000

vector<int> graph[NODES];
bool removido[NODES];

void printq(string str, queue<int> q) {
	cout << str << ": ";
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void removerExternos(int *n) {
	queue<int> q;
	int centro_i = 0, centro = 0;

	for (int x = 1; x <= (*n); x++) {
		if (graph[x].size() == 1) q.push(x);
		else if (graph[x].size() > centro) {
			centro = graph[x].size();
			centro_i = x;
		}
	}

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		removido[cur] = true;
		(*n)--;

		for(int x = 0; x < graph[cur].size(); x++) {
			int a = graph[cur][x];
			if (!removido[a] && graph[a].size() == 2) q.push(a);
		}
	}

	for (int x = 0; x < graph[centro_i].size(); x++) {
		int a = graph[centro_i][x];
		if (graph[a].size() == 2 && !removido[a]) q.push(a);
	}


	removido[centro_i] = true;
	(*n)--;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		removido[cur] = true;
		(*n)--;

		if (graph[cur].size() == 2) {
			int a = graph[cur][0], b = graph[cur][1];
			
			if (!removido[a] && graph[a].size() <= 2) q.push(a);
			if (!removido[b] && graph[b].size() <= 2) q.push(b);
		}
	}

}

int main() {
	int n, m;
	int a, b;

	scanf("%d %d", &n, &m);

	while(m--) {
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	removerExternos(&n);

	printf("%d\n", n);

	return 0;
}
