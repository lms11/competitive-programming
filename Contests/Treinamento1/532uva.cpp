#include <cstdio>
#include <queue>
using namespace std;

#define MAX 30

typedef struct {
	int x, y, z;
} Position;

char grade[MAX][MAX][MAX];
int vis[MAX][MAX][MAX], dist[MAX][MAX][MAX];
int l, r, c;

bool comp(Position a, Position b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
bool comp2(Position a, int x, int y, int z) { return a.x == x && a.y == y && a.z == z; }

void add(queue<Position> *q, int x, int y, int z, int d) {
	if (x >= 0 && y >= 0 && z >= 0 && x < c && y < r && z < l && (grade[x][y][z] == '.' || grade[x][y][z] == 'E') && vis[x][y][z] == 0) {
		vis[x][y][z] = 1;
		dist[x][y][z] = d;

		Position pos;
		pos.x = x;
		pos.y = y;
		pos.z = z;

		(*q).push(pos);
	}
}

int bfs(Position start, Position end) {
	queue<Position> q;
	int i, j, k, d;
	Position cur;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			for (k = 0; k < MAX; k++) {
				vis[i][j][k] = 0;
				dist[i][j][k] = -1;
			}
		}
	}

	q.push(start);
	vis[start.x][start.y][start.z] = 1;
	dist[start.x][start.y][start.z] = 0;

	while (q.empty() == false) {
		cur = q.front();
		d = dist[cur.x][cur.y][cur.z] + 1;
		q.pop();

		if (comp2(end, cur.x-1, cur.y, cur.z) ||
			comp2(end, cur.x, cur.y-1, cur.z) ||
			comp2(end, cur.x+1, cur.y, cur.z) ||
			comp2(end, cur.x, cur.y+1, cur.z) ||
			comp2(end, cur.x, cur.y, cur.z-1) ||
			comp2(end, cur.x, cur.y, cur.z+1)) {
			return d;
		}

		add(&q, cur.x-1, cur.y, cur.z, d);
		add(&q, cur.x, cur.y-1, cur.z, d);
		add(&q, cur.x+1, cur.y, cur.z, d);
		add(&q, cur.x, cur.y+1, cur.z, d);
		add(&q, cur.x, cur.y, cur.z-1, d);
		add(&q, cur.x, cur.y, cur.z+1, d);
	}

	return -1;	
}

int main() {
	int i, j, k;
	Position begin, end;

	while(scanf("%d %d %d", &l, &r, &c), l != 0) {
		for(i = 0; i < l; i++) {
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					scanf(" %c", &grade[k][j][i]);
					
					if (grade[k][j][i] == 'S') {
						begin.z = i;
						begin.y = j;
						begin.x = k;

					} else if (grade[k][j][i] == 'E') {
						end.z = i;
						end.y = j;
						end.x = k;
		
					}
				}
			}
		}

		for (i = l; i < MAX; i++) {
			for (j = r; j < MAX; j++) {
				for (k = c; k < MAX; k++) {
					grade[k][j][i] = 0;
				}
			}
		}

		i = bfs(begin, end);
		
		if (i == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", i);
	}

	return 0;
}
