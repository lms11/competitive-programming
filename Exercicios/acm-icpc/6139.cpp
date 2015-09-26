#include <cstdio>
#include <iostream>
using namespace std;

int bit[100005][2];
int n, q;
int v[100005];

int query(int index, int tree) {
	int sum = 0;
	for (int i = index; i > 0; i -= i & -i) {
		sum += bit[i][tree];
	}
	return sum;
}

void update_neg(int index) {
	for (int i = index; i <= n; i += i & -i)
		bit[i][0]++;
}

void update_zero(int index, int val) {
	for (int i = index; i <= n; i += i & -i)
		bit[i][1] += val;
}

int main() {
	int a, b;
	char c;

	while(scanf("%d %d", &n, &q) != EOF) {
		for (int i = 1; i <= n; i++)
			bit[i][0] = bit[i][1] = v[i] = 0;

		for(int i = 1; i <= n; i++) {
			scanf("%d", &a);
			if (a == 0) update_zero(i, 1);
			else if (a < 0) update_neg(i); 

			v[i] = a;
		}

		while(q--) {
			scanf(" %c %d %d", &c, &a, &b);

/*			if (c == 'D') {
				printf("DEBUG: ");
				for (; a <= b; a++) printf(" %d", v[a]);
				printf("\n");
			}
*/

			if (c == 'C') {
//				printf("C called: %d %d (%d)\n", a, b, v[a]);

				if (b == 0 && v[a] != 0) update_zero(a, 1);
				else {
					if (v[a] == 0 && b != 0)
						update_zero(a, -1);

					if ((v[a] >= 0 && b < 0) || (v[a] < 0 && b > 0))
						update_neg(a);
				}

				v[a] = b;
			}
			else {
				int neg = query(b, 0) - query(a-1, 0);
				int zero = query(b, 1) - query(a-1, 1);

//				printf("P called: A = %d | B = %d | Zero = %d | Negative = %d\n", a, b, zero, neg);

				if (zero > 0) cout << "0";
				else if (neg % 2 == 0) cout << "+";
				else cout << "-";
			}
		}

		cout << endl;
	}

	return 0;
}