#include <cstdio>
#include <cmath>
using namespace std;

#define N 11000

int main() {
	int b, a;

	scanf("%d", &a);

	b = 2;
	for (int x = 2; x <= a/2; x++) {
		if (a % x == 0) b++;
	}

	if (a == 1) printf("%d", 1);
	else printf("%d", b);

	return 0;
}
