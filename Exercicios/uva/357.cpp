#include <cstdio>
using namespace std;

long long int memo[35000][6];
int n;
int moedas[5] = { 1, 5, 10, 25, 50 };

long long int pd(int weight, int i) {
	if (weight == 0) return 1;
	else if (weight < 0 || i > 4) return 0;
	else if (memo[weight][i] != -1) return memo[weight][i];

	return (memo[weight][i] = pd(weight - moedas[i], i) + pd(weight, i+1));
}

int main() {
	int n;

	for (int x = 0; x < 35000; x++)
		for (int y = 0; y < 6; y++)
			memo[x][y] = -1;

	while(scanf("%d", &n) != EOF) {
		long long int res = pd(n, 0);
		if (res == 1) printf("There is only 1 way to produce %d cents change.\n", n);
		else printf("There are %lld ways to produce %d cents change.\n", res, n);
	}

	return 0;
}