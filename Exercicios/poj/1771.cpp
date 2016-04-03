#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int memo[35][35];
int n;

int pd(int i) {
	if (i == n - 1) return 0;
	else if (memo[i] != -1) return memo[i];

	int r1 = (values[i+1] - values[i]) * 4 + 10 + pd(i + 1), 	// Indo de elevador
		r2 = (values[i+1] - values[i]) * 20 + pd(i + 1);		// Indo de escada

	return memo[i] = min(r1, r2);
}

void steps() {
	vector<int> s;
	int r1, r2;

	for (int x = 0; x < (n - 1); x++) {
		r1 = (values[x+1] - values[x]) * 4 + 10 + pd(x + 1);
		r2 = (values[x+1] - values[x]) * 20 + pd(x + 1);

		if (r1 < r2) s.push_back(values[x+1]);
	}

	printf("%lu", s.size());
	for (int x = 0; x < s.size(); x++) printf(" %d", s[x]);
	printf("\n");
}

int main() {
	int a;

	while(scanf("%d", &n), n != 0) {
		memset(memo, -1, sizeof(memo));

		values.push_back(1);

		for (int x = 0; x < n; x++) {
			scanf("%d", &a);
			values.push_back(a);
		}

		values.push_back(5000000);

		printf("%d\n", pd(0));
		steps();
	}

	return 0;
}