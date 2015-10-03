#include <cstdio>

int main() {
	int t, n;
	long long int a, b, c;

	scanf("%d", &n);

	for (t = 1; t <= n; t++) {
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
			if (a == b && a == c) printf("Case %d: Equilateral\n", t);
			else if (a == b || a == c || b == c) printf("Case %d: Isosceles\n", t);
			else printf("Case %d: Scalene\n", t);

		} else {
			printf("Case %d: Invalid\n", t);

		}
	}

	return 0;
}