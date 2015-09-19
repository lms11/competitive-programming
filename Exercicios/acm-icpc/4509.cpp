#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define GRID 31
#define MAX_DIST 2000000000

typedef pair<int, int> pii;

struct Hole {
	int x1, x2, y1, y2;
	int t;
};

int w, h, grav, hholes;
int grid[GRID][GRID];
int dist[GRID][GRID][GRID][GRID]; // dist[x1][y1][x2][y2] == dist from [x1][y1] to [x2][y2]
Hole holes[GRID*GRID-2];


void add(queue<pii > *q, pii from, pii to, int d) {
	int x = to.first, y = to.second;
	if (x >= 0 && x < w && y >= 0 && y < h && grid[x][y] != 36) {
		dist[from.first][from.second][x][y] = d + 1;
		q->push(to);
	}
}

void bfs(int x, int y) {
	queue<pii > q;
	int x2, y2;
	
	dist[x][y][x][y] = 0;

	q.push(pii(x, y));

	while(!q.empty()) {
		pii cur = q.front();
		q.pop();

		add(&q, cur, pii(cur.first+1, cur.second), dist[x][y][cur.first][cur.second]);
		add(&q, cur, pii(cur.first-1, cur.second), dist[x][y][cur.first][cur.second]);
		add(&q, cur, pii(cur.first, cur.second+1), dist[x][y][cur.first][cur.second]);
		add(&q, cur, pii(cur.first, cur.second-1), dist[x][y][cur.first][cur.second]);
	}
}








int main() {
	int x, y, x2, y2, z;

	while (scanf("%d %d", &w, &h), w != 0) {
		queue<pii > bfsQueue;
		bfsQueue.push(pii(0, 0));

		for (int i = 0; i < GRID; i++)
			for (int j = 0; j < GRID; j++)
				for (int k = 0; k < GRID; k++)
					for (int l = 0; l < GRID; l++)
						dist[i][j][k][l] = MAX_DIST;


	    for (int i = 0; i < GRID; i++) { 
    	    for (int j = 0; j < GRID; j++) {
        	    grid[i][j] = 35;
       		}
    	}

		scanf("%d", &grav);
		for (int i = 0; i < grav; i++) {
			scanf("%d %d", &x, &y);
			grid[x][y] = 36;
		}

		scanf("%d", &hhol);
		holes[0].x1 = holes[0].x2 = holes[0].y1 = holes[0].y2 = holes[0].t = 0;

        for (int i = 1; i <= hhol; i++) {
            scanf("%d %d", &x, &y, &x2, &y2, &z);
            grid[x][y] = 37 + z;
			
			holes[i].x1 = x;
			holes[i].y1 = y;
			holes[i].x2 = x2;
			holes[i].y2 = y2;
			holes[i].t = z;

			bfsQueue.push(pii(x, y));
			bfsQueue.push(pii(x2, y2));
        }

		while(!bfsQueue.empty()) {
			bfs(bfsQueue.front().first, bfsQueue.front().second);
			bfsQueue.top();
		}

	}

	return 0;
}