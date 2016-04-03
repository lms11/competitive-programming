#include <stdio.h>

long long int fib[5010];

long long int calc(int n) {
	if (n <= 1) return n;
	else if (fib[n] != 0) return fib[n];
	return fib[n] = calc(n-1) + calc(n-2);	
}

int main() {
	int n;

	while(scanf("%d", &n) != EOF) {
		printf("The Fibonacci number for %d is %lld\n", n, calc(n));
	}

	return 0;
}