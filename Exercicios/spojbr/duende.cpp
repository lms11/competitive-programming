#include <cstdio>
#include <queue>
using namespace std;

#define MAX_SIZE 1000

int n, m;
int matrix[12][12];
int dist[12][12];

typedef pair<int, int> pii;

void add(queue<pii> *q, pii from, int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != 2 && dist[x][y] > dist[from.first][from.second] + 1) {
		(*q).push(pii(x, y));
		dist[x][y] = dist[from.first][from.second] + 1;
	}
}

int bfs(int x, int y) {
	queue<pii> q;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			dist[i][j] = MAX_SIZE;
		}
	}

	q.push(pii(x, y));
	dist[x][y] = 0;

	while(!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (matrix[cur.first][cur.second] == 0) return dist[cur.first][cur.second];

		add(&q, cur, cur.first+1, cur.second);
		add(&q, cur, cur.first-1, cur.second);
		add(&q, cur, cur.first, cur.second+1);
		add(&q, cur, cur.first, cur.second-1);
	}

	return MAX_SIZE;
}

int main() {
	scanf("%d %d", &n, &m);
	int x, y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &matrix[i][j]);
			
			if (matrix[i][j] == 3) {
				x = i;
				y = j;
			}
		}
	}

	printf("%d", bfs(x, y));

	return 0;

}
