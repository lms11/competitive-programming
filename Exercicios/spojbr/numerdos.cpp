#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

#define NODES 1000

vector<int> graph[NODES];
int dist[NODES];
bool visited[NODES];

void bfs() {
	queue<int> q;
	q.push(0);

	dist[0] = 0;
	visited[0] = true;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int x = 0; x < graph[cur].size(); x++) {
			int y = graph[cur][x];
			
			if (visited[y]) continue;

			dist[y] = dist[cur] + 1;
			visited[y] = true;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, k, index, x, y, z, i, j, t = 1;
	char last;
	string a, b;
	vector<int> authors;
	map<pair<string, string>, int> dict;
	pair<string, string> erdos = make_pair(string("Erdos"), string("P."));

	while(cin >> n, n != 0) {
		for (x = 0; x < NODES; x++) {
			graph[x].clear();
			dist[x] = 2000000000;
			visited[x] = false;
		}

		k = 1;
		dict.clear();
		dict[erdos] = 0;

		for (x = 0; x < n; x++) {
			while(true) {
				cin >> a;
				cin >> b;

				last = b[b.length() - 1];
				index = 1;
				b.pop_back();
				pair<string, string> name = make_pair(b, a);

				if (dict.count(name) > 0) {
					index = dict[name];

				} else {
					dict[name] = index = k++;
				}

				authors.push_back(index);

				if (last == '.') break;
			}

			for (z = 0; z < authors.size(); z++) {
				i = authors[z];

				for (y = 0; y < z; y++) {
					j = authors[y];

					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}

			authors.clear();
		}

		bfs();

		cout << "Teste " << t++ << endl;
		for (map<pair<string, string>, int>::iterator it = dict.begin(); it != dict.end(); it++) {
			if (it->second == 0) continue; // erdos himself

			cout << it->first.second << " " << it->first.first << ": ";

			if (dist[it->second] == 2000000000) cout << "infinito" << endl;
			else cout << dist[it->second] << endl;
		}
		cout << endl;
	}

	return 0;
}
