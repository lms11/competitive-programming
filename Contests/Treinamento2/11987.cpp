#include <cstdio>
#include <vector>
using namespace std;

int n, m, a, b, c;
int id[100010];
vector<int> sets[100010];

void unify(int a, int b);
int find(int a);
void insert(int a, int b);
int size(int a);
long long int sum(int a);

void debug() {
	int x;
	vector<int>::iterator it;

	printf("Index:");
	for (x = 1; x <= n; x++) printf(" %d", x);
	printf("\nRoot: ");
	for (x = 1; x <= n; x++) printf(" %d", id[x]);

	for (x = 1; x <= n; x++) {
		printf("\n[%d] =>", x);

		for (it = sets[x].begin(); it != sets[x].end(); it++) printf(" %d", *it);

	}

	printf("\n");
	printf("===== ===== ===== ===== ===== =====\n");
	printf("===== ===== ===== ===== ===== =====\n\n");
}


// Union set (a) with set (b)
void unify(int a, int b) {
	int root_a = find(a),
		root_b = find(b);

	if (root_a == root_b) return;

	// Weighted quick-union
	if (size(root_a) < size(root_b)) {
		// Since set (a) is smaller than set (b)
		// Let's insert a into b (advantage here: height of subset (a) is smaller)

		sets[root_b].insert(sets[root_b].end(), sets[root_a].begin(), sets[root_a].end());
		sets[root_a].clear();
		id[a] = id[root_a] = root_b;

	} else {
		// Set (b) is smaller or equal to set (a)

		sets[root_a].insert(sets[root_a].end(), sets[root_b].begin(), sets[root_b].end());
		sets[root_b].clear();
		id[b] = id[root_b] = root_a;

	}	
}

// Find root of (a)
int find(int a) {
	while(a != id[a]) {
		a = id[a] = id[id[a]]; // Go to root with path compression
	}
	return a;
}

// Insert (a) into set (b)
void insert(int a, int b) {
	int root_a = find(a),
		root_b = find(b),
		new_father = 0;
	
	vector<int>::iterator it;

	if (root_a == root_b) return;

	it = sets[root_a].begin();
	while (*it != a) it++;
	
	// Remove a from its original set
	sets[root_a].erase(it);

	// Insert a into new set
	sets[root_b].push_back(a);

	// Set new root id
	id[a] = root_b;


	if (size(a) > 0) {
		// Send each child of (a) to a different father within the same old set
		
		// First lets check if (a) was the head of the tree
		if (a == root_a) new_father = sets[a].front();
		else new_father = root_a;

		for (it = sets[a].begin(); it != sets[a].end(); it++) {
			id[*it] = new_father;
		}

		sets[new_father].insert(sets[new_father].begin(), sets[a].begin(), sets[a].end());
		sets[a].clear();
	}
}

// Size of set (a)
int size(int a) {
	return sets[a].size();
}

// Sum of set (a)
long long int sum(int a) {
	long long int sum = 0;
	vector<int>::iterator it;

	for (it = sets[a].begin(); it != sets[a].end(); it++) sum += *it;

	return sum;
}


int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		// Reset variables
		for (a = 1; a <= n; a++) {
			id[a] = a;
			sets[a].clear();
			sets[a].push_back(a);
		}

		while(m--) {
			scanf("%d", &a);

			if (a == 1 || a == 2) {
				scanf("%d %d", &b, &c);

				if (a == 1) unify(b, c);
				else insert(b, c);

			} else if (a == 3) {
				scanf("%d", &b);

				b = find(b);
				printf("%d %lld\n", size(b), sum(b));

//				debug();

			}
		}

	}

	return 0;
}
