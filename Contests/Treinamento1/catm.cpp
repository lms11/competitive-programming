#include <cstdio>
#include <queue>
using namespace std;

#define MAX 110

typedef struct {
	int x, y;
} Position;

int grid[MAX][MAX];
int w, h;

bool validCoord(int x, int y) {
//	printf("Validando (%d, %d): %d\n", x, y, (x >= 1 && y >= 1 && x <= w && y <= h));
	return x >= 1 && y >= 1 && x <= w && y <= h;
}

void add(queue<Position> *q, int x, int y, int v) {
//	printf("Pintar (%d, %d) de %d. Validação: [ %d && (%d || %d) ]\n", x, y, v, validCoord(x, y), (v == 1 && grid[x][y] == 0), (v == 2 && grid[x][y] < 2));

	if (validCoord(x, y) && ((v == 1 && grid[x][y] == 0) || (v == 2 && grid[x][y] < 2))) {

		Position p;
		p.x = x;
		p.y = y;

		grid[x][y] = v;
		(*q).push(p);

	}
}

bool bfs(Position rat, Position cat1, Position cat2) {
	queue<Position> q;
	int i, j;
	Position cur;

	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			grid[i][j] = 0;


	grid[rat.x][rat.y] = 1;
	grid[cat1.x][cat1.y] = grid[cat2.x][cat2.y] = 2;

	q.push(rat);
	q.push(cat1);
	q.push(cat2);

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (grid[cur.x][cur.y] == 1 && !(validCoord(cur.x-1, cur.y) && validCoord(cur.x+1, cur.y) && validCoord(cur.x, cur.y-1) && validCoord(cur.x, cur.y+1))) {
			return true;
		}

		add(&q, cur.x-1, cur.y, grid[cur.x][cur.y]);
		add(&q, cur.x+1, cur.y, grid[cur.x][cur.y]);
		add(&q, cur.x, cur.y-1, grid[cur.x][cur.y]);
		add(&q, cur.x, cur.y+1, grid[cur.x][cur.y]);
	}

	return false;
}

int main() {
	int n;
	Position rat, cat1, cat2;

	scanf("%d %d %d", &h, &w, &n);

	while(n--) {
		scanf("%d %d %d %d %d %d", &rat.y, &rat.x, &cat1.y, &cat1.x, &cat2.y, &cat2.x);

		if (bfs(rat, cat1, cat2)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
