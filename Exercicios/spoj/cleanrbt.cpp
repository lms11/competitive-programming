#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 30
#define MAX_DISTANCE 2000000000

char m[SIZE][SIZE];
int dist[SIZE*SIZE][SIZE*SIZE];
int pdMem[3000][15];
vector<pair<int, int> > nodes;
int w, h, special_one;

int distId(int y, int x) {
		return y * w + x;
}

void add(queue<pair<int, int> > *q, int y, int x, int f, int d) {
		int f2 = distId(y, x);
		if (y >= 0 && x >= 0 && y < h && x < w && m[y][x] != 'x' && dist[f][f2] > d + 1) {
				dist[f][f2] = d + 1;
				//dist[f2][f] = d + 1;
				q->push(make_pair(y, x));
		}	
}

// find distance using bfs approach (returns true if, and only if, finds distance to all nodes)
void calculateDistance(pair<int, int> start) {
		queue<pair<int, int> > q;
		int n = nodes.size() - 1;
		int z = distId(start.first, start.second);	
		int tmpdist;

		q.push(start);

		dist[z][z] = 0;

		while(!q.empty()) {
				int y = q.front().first, x = q.front().second;
				q.pop();

				if (m[y][x] == '*' && y != start.first && x != start.second) n--;
				if (n == 0) break;

				tmpdist = dist[z][distId(y, x)];

				add(&q, y-1, x, z, tmpdist);
				add(&q, y+1, x, z, tmpdist);
				add(&q, y, x-1, z, tmpdist);
				add(&q, y, x+1, z, tmpdist);
		}
}

int min(int a, int b) { return a < b ? a : b; }

int indexToDistId(int i) {
		return distId(nodes[i].first, nodes[i].second);
}

int pd(int bitmask, int node, int n) {
		int numBits;
		if (pdMem[bitmask][node] != -1) return pdMem[bitmask][node];
		
		// Recursion base
		if (n == nodes.size()) return 0;

		int mindist = MAX_DISTANCE;
		for (int x = 0; x < nodes.size(); x++) {
				if (x == node || (1<<x & bitmask)) continue;

				mindist = min(mindist, dist[indexToDistId(node)][indexToDistId(x)] + pd(bitmask | 1<<x, x, n+1));
		}

		pdMem[bitmask][node] = mindist;
		return mindist;
}

int main() {
		bool res;

		while (scanf("%d %d", &w, &h), w != 0) {
				nodes.clear();

				for (int i = 0; i < 3000; i++) for (int j = 0 ; j < 15; j++) pdMem[i][j] = -1;
				for(int i = 0; i < SIZE*SIZE; i++) for (int j = 0; j < SIZE*SIZE; j++) dist[i][j] = MAX_DISTANCE;

				for (int i = 0; i < h; i++) {
						for (int j = 0; j < w; j++) {
								scanf(" %c", &m[i][j]);

								if (m[i][j] == 'o' || m[i][j] == '*') {
										nodes.push_back(make_pair(i, j));
										if (m[i][j] == 'o') special_one = (nodes.size() - 1);
								}
						}
				}

				for (int x = 0; x < nodes.size(); x++) {
						calculateDistance(nodes[x]);
				}

				bool res = true;
				for (int i = 0; res && i < nodes.size(); i++)
					for (int j = 0; res && j < nodes.size(); j++) {
						res = dist[indexToDistId(i)][indexToDistId(j)] != MAX_DISTANCE;
					}
				
				if (!res) printf("-1\n");
				else {
						printf("%d\n", pd(1<<special_one, special_one, 1));
				}

		}

		return 0;
}
