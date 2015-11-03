/*
	Union Find

	Complexity:
		Find: O(1) quando amortizado
		Union: O(m lg(n))
*/

using namespace std;

#define SETS 1000

int unionFind[SETS];
int unionFindLen[SETS];


int find(int node) {
	if (unionFind[node] != node) 
		unionFind[node] = find(unionFind[node]);

	return unionFind[node];
}

void union(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (unionFindLen[a] > unionFindLen[b]) {
		unionFind[b] = a;
		unionFindLen[a] += unionFindLen[b];

	} else {
		unionFind[a] = b;
		unionFindLen[b] += unionFindLen[a];

	}
}

void reset() {
	for (int i = 0; i < SETS; i++) {
		unionFind[i] = i;
		unionFindLen[i] = 1;
	}
}