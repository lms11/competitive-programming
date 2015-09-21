#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

#define WEIGHT 	11000
#define INF		2000000000

int memo[WEIGHT];
vector<pii> moedas;
int pig_e, pig_full;

int pd(int weight) {
	if (weight == 0) return 0;
	else if (weight < 0) return INF;
	else if (memo[weight] != -1) return memo[weight];

	int res = INF;

	for (int x = 0; x < moedas.size(); x++) {
		res = min(res, moedas[x].first + pd(weight - moedas[x].second));
	}

	return memo[weight] = res;
}

int main() {
	int t, n, a, b;

	scanf("%d", &t);

	while(t--) {
		moedas.clear();

		for (int x = 0; x < WEIGHT; x++) memo[x] = -1;

		scanf("%d %d %d", &pig_e, &pig_full, &n);

		while(n--) {
			scanf("%d %d", &a, &b);

			moedas.push_back(pii(a, b));
		}

		int res = pd(pig_full - pig_e);
		if (res == INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", res);
	}

	return 0;
}