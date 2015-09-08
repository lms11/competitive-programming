#include <cstdio>
#include <cmath>
using namespace std;

#define MOD 10000007
#define lli long long int

lli mpow(lli base, lli exponent) {
	lli result = 1;
	base %= MOD;
	while (exponent > 0) {
		if (exponent % 2)
			result = (result * base) % MOD;
		exponent = exponent >> 1;
		base = (base * base) % MOD;
	}
	return result;
}

lli min(lli a, lli b) {
	return a < b ? a : b;
}

lli max(lli a, lli b) {
	return a > b ? a : b;
}

int main() {
	lli a, b;

	while (scanf("%lld %lld", &a, &b), a != 0) {
		lli c, d, e, f, g, h;

		c = mpow(a, min(a, b));
		d = mpow(a, max(a, b) - min(a, b));
		g = (c * (1 + d)) % MOD;		

		e = mpow(a-1, min(a-1, b));
		f = mpow(a-1, max(a-1, b) - min(a-1, b));
		h = (e * (1 + f)) % MOD;
		h = (2 * h) % MOD;

		printf("%lld\n", (g + h) % MOD);
	}

	return 0;
}


