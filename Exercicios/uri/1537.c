#include <stdio.h>

int main() {
	long long int n, sum;

	while(scanf("%lld", &n), n >= 3) {
		sum = 1;

		while(n > 3) {
			sum = (n * (sum % 1000000009)) % 1000000009;
			n--;
		}


		printf("%lld\n", sum);
	}

	return 0;
}
