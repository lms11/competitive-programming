#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	unsigned long long int l, r, k;
	unsigned long long int x, y, z;
	vector<long long int> values;

	//scanf("%lld %lld %lld", &l, &r, &k);
	cin >> l >> r >> k;

	x = floor(log(l) / log(k));
	y = ceil(log(r) / log(k));

	z = 0;
	while (x <= y) {
		z = pow(k, x++);
		if (z >= l && z <= r) values.push_back(z);
	}

	if (values.size() == 0) cout << "-1" << endl; // printf("-1\n");
	else {
		for (x = 0; x < values.size(); x++) {
			//printf("%lld ", values[x]);
			cout << values[x] << " ";
		}
		//printf("\n");
		cout << endl;
	}

	return 0;
}
