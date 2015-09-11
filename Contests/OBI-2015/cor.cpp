#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

char m[1010][1010];
int N;

void add(int x, int y, char l, queue<pii> *q) {
	if (x >= 0 && y >= 0 && x < N && y < N && m[x][y] == '*') {
		m[x][y] = l;
		(*q).push(pii(x, y));
	}
}

void visit(queue<pii> *q, pii cur) {
	int x = cur.first, y = cur.second;
	char l = m[x][y] + 1;

	add(x+1, y, l, q);
	add(x-1, y, l, q);
	add(x, y+1, l, q);
	add(x, y-1, l, q);
}

void bfs() {
	queue<pii> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == '0') q.push(pii(i, j));
		}
	}

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (m[cur.first][cur.second] == '9') continue;
		visit(&q, cur);
	}
}

int main() {
	scanf("%d", &N);
	
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			scanf(" %c", &m[i][j]);

	bfs();

	for (int j = 0; j < N; j++, printf("\n"))
		for (int i = 0; i < N; i++)
			printf("%c", m[i][j] == '*' ? '9' : m[i][j]);

	return 0;
}
