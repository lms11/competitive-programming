#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int direito[50], esquerdo[50];
	int n, m, count;
	char c;

	while(scanf("%d", &n) != EOF) {
		memset(direito, 0, sizeof direito);
		memset(esquerdo, 0, sizeof esquerdo);

		while(n--) {
			scanf("%d %c", &m, &c);

			if (c == 'E') esquerdo[m-30]++;
			else direito[m-30]++;
		}

		count = 0;
		for (int i = 0; i < 50; i++) {
			count += min(direito[i], esquerdo[i]);
		}

		printf("%d\n", count);
	}

	return 0;
}