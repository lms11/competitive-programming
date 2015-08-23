#include <cstdio>
#include <queue>
using namespace std;

#define MAX 30 // 30 (+- no letters in alphabet)

int vis[MAX], pai[MAX], lev[MAX];
vector<char> bl, el; // begin and end letters
vector<int> graph[MAX];

int con(char c) { return c - 'A'; }
char conb(int c) { return (char)(c + 'A'); }

void bfs() {
	queue<int> q;
	int i, cur;

	for (i = 0; i < MAX; i++) {
		vis[i] = 0;
		pai[i] = lev[i] = -1;
//		graph[i].clear();
	}

	i = con('R');
	q.push(i); // always starts at Rome
	vis[i] = 1;
	lev[i] = 0;

	while(q.empty() == false) {
		cur = q.front();
		q.pop();		

		while(graph[cur].empty() == false) {
			i = graph[cur].back();

			if (vis[i] == 0) {
				q.push(i);
				vis[i] = 1;
				pai[i] = cur;
				lev[i] = lev[cur] + 1;
			}
			
			graph[cur].pop_back();
		}
	}
}

void calc(int begin, int end) {
	int cur_l = begin, cur_r = end;
	vector<char>::iterator it;
	vector<char>::reverse_iterator rit;

	bl.clear();
	el.clear();

//	printf("COMEÇANDO QUERY %c <-> %c\n", conb(begin), conb(end));
//	printf("Level L: %d || Level R: %d\n", lev[cur_l], lev[cur_r]);

	while(lev[cur_l] != lev[cur_r]) {
		if (lev[cur_l] < lev[cur_r]) {
			// Level de R tá maior, diminui ele
			el.push_back(conb(cur_r));
			cur_r = pai[cur_r];

		} else {
			// Level de L tá maior, diminui ele
			bl.push_back(conb(cur_l));
			cur_l = pai[cur_l];

		}

//		printf("Level L: %d || Level R: %d\n", lev[cur_l], lev[cur_r]);
	}

	while(cur_l != cur_r) {
		el.push_back(conb(cur_r));
		cur_r = pai[cur_r];		

		bl.push_back(conb(cur_l));
		cur_l = pai[cur_l];
	}

	// Printa
	for (it = bl.begin(); it != bl.end(); it++) printf("%c", *it);
	printf("%c", conb(cur_l));
	for (rit = el.rbegin(); rit != el.rend(); rit++) printf("%c", *rit);

	printf("\n");
}

int main() {
	char name1[100], name2[100];
	int n, t, m, q, i; 

	scanf("%d", &n);

	for (t = 0; t < n; t++) {
		scanf("%d %d", &m, &q);

		for(i = 0; i < m; i++) {
			scanf(" %s %s", name1, name2);

			graph[con(name1[0])].push_back(con(name2[0]));
			graph[con(name2[0])].push_back(con(name1[0]));

//			printf("[DEBUG] Ligando %c (%d) com %c (%d)\n", name1[0], con(name1[0]), name2[0], con(name2[0]));
		}

		bfs(); // Build levels and pais arrays

		for (i = 0; i < q; i++) {
			scanf(" %s %s", name1, name2);
			calc(con(name1[0]), con(name2[0]));
		}

		if (t < n-1) printf("\n");
	}

	return 0;
}
