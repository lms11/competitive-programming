#include <stdio.h>

int main() {
	int v[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	int t;
	char in;
	long long sum;

	scanf("%d", &t);
	scanf("%c", &in);

	while(t--) {
		sum = 0;
		while(scanf("%c", &in), in != '\n') {
			sum += v[in-'0'];
		}
	
		printf("%lld leds\n", sum);
	}

	return 0;
}
