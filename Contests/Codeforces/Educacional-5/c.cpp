#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1005

typedef pair<int, int> pii;

bool vis[MAX][MAX];
char matrix[MAX][MAX];
int uf[MAX*MAX], size[MAX*MAX];
int n, m;

#define pairToIndex(p) (p.first * MAX + p.second)

int find(int a) {
	while (a != uf[a]) a = uf[a];
	return a;
}

void join(pii a, pii b) {
	int i_a = find(pairToIndex(a)), i_b = find(pairToIndex(b));

	if (i_a == i_b) return;

	if (size[i_a] > size[i_b]) {
		uf[i_b] = i_a;
		size[i_a] += size[i_b];

	} else {
		uf[i_a] = i_b;
		size[i_b] += size[i_a];

	}
}

void bfs(pii p) {
	int i, j;
	queue<pii> q;
	q.push(p);

	while(!q.empty()) {
		pii cur = q.front();
		i = cur.first, j = cur.second;
		q.pop();

		vis[cur.first][cur.second] = true;
		
		if (i-1 >= 0 && matrix[i-1][j] == '.' && vis[i-1][j] == false) {
			pii p = pii(i-1, j);
			q.push(p);
			join(p, cur);
		}

		if (i+1 < n && matrix[i-1][j] == '.' && vis[i-1][j] == false) {
			pii p = pii(i-1, j);
			q.push(p);
			join(p, cur);
		}

		if (j-1 >= 0 && matrix[i][j-1] == '.' && vis[i][j-1] == false) {
			pii p = pii(i, j-1);
			q.push(p);
			join(p, cur);
		}
		
		if (j+1 < m && matrix[i][j+1] == '.' && vis[i][j+1] == false) {
			pii p = pii(i, j+1);
			q.push(p);
			join(p, cur);
		}
	}
}

int main() {
	int k, i, j;
	int a, b, c, d;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			k = pairToIndex(pii(i, j));
			uf[k] = k;
			size[k] = 1;		
		}
	}

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf(" %c", &matrix[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] == '.' && vis[i][j] == false) {
				pii p = pii(i, j);
				bfs(p);
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] == '.') printf(".");
			else {
				k = 1;
				a = -1; b = -2; c = -3; d = -4;

				if ((i-1) >= 0 && matrix[i-1][j] == '.') {
					a = find(pairToIndex(pii(i-1, j)));
					k += size[a];
				}

				if ((i+1) < n && matrix[i+1][j] == '.') {
					b = find(pairToIndex(pii(i+1, j)));

					if (b != a) k += size[b];
				}

				if ((j-1) >= 0 && matrix[i][j-1] == '.') {
					c = find(pairToIndex(pii(i, j-1)));

					if (c != b && c != a) k += size[c];
				}

				if ((j+1) < m && matrix[i][j+1] == '.') {
					d = find(pairToIndex(pii(i, j+1)));
					
					if (d != c && d != b && d != a) k += size[d];
				}


				printf("%d", k % 10);

			}
		}
		printf("\n");
	}

	return 0;
}
