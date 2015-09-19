#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

#define GRID 150
#define DIST_MAX 2000000000

// dir => 1: left, 2: right, 3: bottom, 4: up

int dist[GRID][GRID];
char m[GRID][GRID];
int w, h;

bool valid(int y, int x) {
	return y >= 0 && y < h && x >= 0 && x < w && m[y][x] != '*'; 
}

void push(queue<tuple<int,int,int> > *q, int y, int x, int d, int ndir) {
	if (dist[y][x] > d + 1) {
		q->push(make_tuple(y, x, ndir));
		dist[y][x] = d + 1;
	}
}

void add(queue<tuple<int,int,int> > *q, tuple<int,int,int> cur, int ndir) {
	int y, x;
	tie(y, x, ignore) = cur;

	int d = dist[y][x];

	if (ndir == 1) { 
		while(valid(y, --x)) {
			push(q, y, x, d, ndir);
		}

	} else if (ndir == 2) {
		while(valid(y, ++x)) {
			push(q, y, x, d, ndir);
		}

	} else if (ndir == 3) {
		while(valid(--y, x)) {
			push(q, y, x, d, ndir);
		}

	} else if (ndir == 4) {
		while(valid(++y, x)) {
			push(q, y, x, d, ndir);
		}
	}
}

void printq(queue<tuple<int,int,int> > q) {
	printf("Exibindo fila atual: ");

	while(q.empty() == false) {
		int i, j, k;
		tie(i, j, k) = q.front();
		q.pop();
		
		printf("(%d, %d, %d) | ", i, j, k);
	}

	printf("\n");
}

int bfs(tuple<int, int, int> from, tuple<int, int, int> to) {
	int y, x, y2, x2;
	queue<tuple<int,int,int> > q;

	tie(y, x, ignore) = from;
	tie(y2, x2, ignore) = to;

	for(int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dist[i][j] = DIST_MAX;
		}
	}

	dist[y][x] = 0;

	add(&q, from, 1);
	add(&q, from, 2);
	add(&q, from, 3);
	add(&q, from, 4);

	//printf("\n[ANTES (%d, %d)] ", y, x);
	//printq(q);

	while(!q.empty()) {
		tuple<int,int,int> cur = q.front();
		q.pop();

		int i, j, dir;
		tie(i, j, dir) = cur;

		if (m[i][j] == 'C' && i != y && j != x)
			return dist[i][j];

		if (dir == 3 || dir == 4) {
			add(&q, cur, 1);
			add(&q, cur, 2);		
		
		} else {
			add(&q, cur, 3);
			add(&q, cur, 4);
		}

	}

	return dist[y2][x2];
}

int main() {
	scanf("%d %d", &w, &h);
	int y = -1, x = -1, x2, y2;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &(m[i][j]));
			if (m[i][j] == 'C') {
				if(y == -1) y = i, x = j;
				else y2 = i, x2 = j;
			}
		}
	}

/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
*/

	printf("%d\n", bfs(make_tuple(y, x, 0), make_tuple(y2, x2, 0))-1);

	return 0;
}

