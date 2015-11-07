#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

#define ALPHA	50
#define INF		2000000000

int  tempo[ALPHA][ALPHA]; // [a-z]
char dest[ALPHA][ALPHA];  // [a-z]

int memo[300][300][30]; // limit: 200 symbols

int map[ALPHA];	// 0 (a) => pos of a, ...

char input[300];
unsigned int length;

inline int gettempo(char a, char b) {
	return tempo[map[a - 'a']][map[b - 'a']];
}

inline char getdest(char a, char b) {
	return dest[map[a - 'a']][map[b - 'a']];
}

// input goes from [a, b]
char pd(int start, int end) {
	if (memo[start][end] != INF)
		return memo[start][end];

	if (end - start == 0) {
		memo[start][end] = 0;
		return input[start];

	} else if (end - start == 1) {
		memo[start][end] = gettempo(input[start], input[end]);
		return getdest(input[start], input[end]);

	} else {
		int min_i = INF, tmp3;
		char tmp1, tmp2;

		for (int i = start; i < end; i++) {
			tmp1 = pd(start, i);
			tmp2 = pd(i+1, end);
			tmp3 = gettempo(tmp1, tmp2);

			memo[start][end][getdest(tmp1, tmp2)] = 
				min(
					memo[start][end][getdest(tmp1, tmp2)], 
					memo[start][end][]

					tmp1 + tmp2 + tmp3);

			if (min_i >= tmp1 + tmp2 + tmp3) {
				min_i = tmp1 + tmp2 + tmp3;
				min_c = getdest(memo_char[start][i], memo_char[i+1][end]);
			}
		}

		memo[start][end] = min_i;
		memo_char[start][end] = min_c;
	}

	return memo[start][end];
}

int main() {
	int k, i, j, k, a, b;
	char c;

	while(scanf("%d", &k), k != 0) {
		a = b = 0;

		for (i = 0; i < k; i++)  {
			scanf(" %c", &c);

			map[c-'a'] = a++;
		}

		for (i = 0; i < k; i++) {
			for (j = 0; j < k; j++) {
				scanf(" %d-%c", &a, &c);

				tempo[i][j] = a;
				dest[i][j] = c;
			}
		}

		scanf("%d", &b);

		while(b--) {
			scanf(" %s", input);

			length = strlen(input);

			for (i = 0; i < 300; i++) {
				for (j = 0; j < 300; j++) {
					for (k = 0; k < 30; k++) {
						memo[i][j][k] = INF;
					}
				}
			}


			pd(0, length-1);
			printf("%d-%c\n", memo[0][length-1], memo_char[0][length-1]);
		}

		printf("\n");
	}


	return 0;
}