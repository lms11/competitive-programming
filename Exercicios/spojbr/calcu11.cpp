#include <cstdio>
#include <cmath>
using namespace std;

int oper[10];

int main() {
	int n, a;
	unsigned long long int value = 1;
	char b;

	scanf("%d", &n);

	while(n--) {
		scanf("%d %c", &a, &b);
		int multi = b == '*' ? 1 : -1;

		if (a == 4)
			oper[2] += 2 * multi;
		else if (a == 6) {
			oper[2] += 1 * multi;
			oper[3] += 1 * multi;

		} else if (a == 8) {
			oper[2] += 3 * multi;

		} else if (a == 9) {
			oper[3] += 2 * multi;

		} else {
			oper[a] += 1 * multi;
	
		}

	}

	for (int x = 1; x < 10; x++) {
		value *= (int)pow(x, oper[x]);
	}

	printf("%llu", value);

	return 0;

}
