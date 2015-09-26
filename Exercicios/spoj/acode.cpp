#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 6000

int memo[MAX];
char in[MAX];
int size;

int to_n(char c) { return c - '0'; }

int pd(int n) {
	if (in[n] == '0') return 0;
	if (n == size) return 1;
	else if (n >= size) return 0;
	else if (memo[n] != -1) return memo[n];

	int res = pd(n+1),
		tmp = to_n(in[n]) * 10 + to_n(in[n + 1]);

	if (n < size - 1 && tmp <= 26 && tmp > 0) res += pd(n+2);

	// printf("N: %d | In[n] = %c | Tmp: %d | Size: %d\n", n, in[n], tmp, size);

	return memo[n] = res;
}

int main() {
	char c;

	while(scanf("%s", in), in[0] != '0') {
		memset(memo, -1, sizeof memo);

		size = strlen(in);

		printf("%d\n", pd(0));
	}

	return 0;
}