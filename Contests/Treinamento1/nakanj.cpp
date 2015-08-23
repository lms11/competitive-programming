#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 8 // 8x8 chessboard

typedef struct {
	int x, y; // x => [a, h] => [0, 7] || y => [1, 8] => [0, 7]
} Position;

void add(int x, int y);

int visited[MAX][MAX], dist[MAX][MAX];
Position cur_node;
queue<Position> q;

int bfs(Position begin, Position end) {
	int i, j;

	for (i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			visited[i][j] = 0;
			dist[i][j] = -1;
		}
	}

	while (q.empty() == false) q.pop();
	q.push(begin);

	visited[begin.x][begin.y] = 1;
	dist[begin.x][begin.y] = 0;

	while(q.empty() == false) {
		cur_node = q.front();
		q.pop();

		if (cur_node.x == end.x && cur_node.y == end.y) {
			return dist[cur_node.x][cur_node.y];	
		}

		add(-1, -2);
		add(-2, -1);
		add(1, -2);
		add(2, -1);
		add(-2, 1);
		add(-1, 2);
		add(1, 2);
		add(2, 1);
	}
	
	return -1;
}

void add(int x, int y) {
	x = cur_node.x + x;
	y = cur_node.y + y;

	if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && visited[x][y] == 0) {
		Position a;
		a.x = x;
		a.y = y;
		visited[x][y] = 1;
		dist[x][y] = dist[cur_node.x][cur_node.y] + 1;
		q.push(a);
	}
}

int con(char c) {
	return c - 'a';
}

int main() {
	int n, bx, by, ex, ey;
	char aux1, aux2;
	Position b, e;

	scanf("%d", &n);

	for(int t = 0; t < n; t++) {
		scanf(" %c%d %c%d", &aux1, &by, &aux2, &ey);
		bx = con(aux1);
		ex = con(aux2);

		b.x = bx;
		b.y = by - 1;
		e.x = ex;
		e.y = ey - 1;

		printf("%d\n", bfs(b, e));
	}

	return 0;
}
