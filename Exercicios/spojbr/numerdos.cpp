#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define NODES 1100

vector<int> graph[NODES];
map<pair<string, string>, int> mapa;
pair<string, string> erdos = make_pair(string("Erdos"), string("P."));
int dist[NODES];

void bfs() {
	queue<int> q;
	
	for (int x = 0; x < NODES; x++) dist[x] = 2000000000;

	dist[0] = 0;

	for (int x = 0; x < graph[0].size(); x++) {
		int u = graph[0][x];
		dist[u] = 1;
		q.push(u);
	}

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int x = 0; x < graph[cur].size(); x++) {
			int u = graph[cur][x];

			if (dist[u] > dist[cur] + 1) {
				dist[u] = dist[cur] + 1;
				q.push(u);
			}
		}
	}
}

void ans() {
	for (map<pair<string, string>, int>::iterator it = mapa.begin(); it != mapa.end(); it++) {
		pair<string, string> name = it->first;
		int index = it->second;

		if (index == 0) continue;

		cout << name.second << " " << name.first << ": ";
		
		if (dist[index] == 2000000000)
			cout << "infinito";
		else
			cout << dist[index];

		cout << endl;
	}
}

int main() {
	int t = 1, n, k = 1;
	string a, b;

	while(scanf("%d", &n), n != 0) {
		mapa[erdos] = 0;

		for (int x = 0; x < n; x++) {
			vector<int> as;

			while(true) {
				cin >> a;
				cin >> b;

				char last = b[b.size()-1];
				b.pop_back();
				pair<string, string> u = make_pair(b, a);
				int v;

				if (mapa.count(u) == 0) {
					v = k++;
					mapa[u] = v;

				} else v = mapa[u];			

				as.push_back(v);

				if (last == '.') break;
			}

			for (int i = 0; i < as.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (i == j) continue;

					graph[as[i]].push_back(as[j]);
					graph[as[j]].push_back(as[i]);	
				}
			}
		}

		bfs();
		cout << "Teste " << t++ << endl;
		ans();
		cout << endl;

		mapa.clear();
		for (int x = 0; x < NODES; x++) graph[x].clear();
	}


}
