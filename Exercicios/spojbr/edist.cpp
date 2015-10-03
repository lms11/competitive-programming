#include <cstdio>
#include <cstring>

#define MAX 2100

int memo[MAX][MAX];
char str_a[MAX], str_b[MAX];

int min(int a, int b, int c) {
	if (a < b)
		if (a < c) return a;
		else return c;
	else
		if (b < c) return b;
		else return c;
}

int pd(int len_a, int len_b) {
	if (len_a == 0) return len_b;
	else if (len_b == 0) return len_a;
	else if (memo[len_a][len_b] != -1) return memo[len_a][len_b];

	int cost = str_a[len_a - 1] == str_b[len_b - 1] ? 0 : 1;

	return memo[len_a][len_b] = min( pd(len_a - 1, len_b) + 1, pd(len_a, len_b - 1) + 1, pd(len_a - 1, len_b - 1) + cost );
}

int main() {
	int t;

	scanf("%d", &t);

	while(t--) {
		memset(memo, -1, sizeof memo);

		scanf(" %s %s", str_a, str_b);

		printf("%d\n", pd(strlen(str_a), strlen(str_b)));
	}
}