#include <cstdio>
using namespace std;

int bit[10010];
int n;

long long int query(int index) {
	long long int sum = 0;
	for (int i = index; i > 0; i -= i & -i)
		sum += bit[i];
	return sum;
}

void update(int index, int val) {
	if (index == 0) return;
	for (int i = index; i <= n; i += i & -i)
		bit[i] += val;
}

int main() {
	int t, a, b, c;
	int q;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &q);

		for (int x = 0; x <= n; x++)
			bit[x] = 0;

		while(q--) {
			scanf("%d %d %d", &a, &b, &c);
			a++; b++;

			update(a, c);
			update(b+1, -c);
		}

		scanf("%d", &q);

		while(q--) {
			scanf("%d", &a);
			a++;

			printf("%lld\n", query(a));
		}
	}
}