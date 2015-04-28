#include <iostream>
using namespace std;

long long int bsearch (long long int vector[], long long int start, long long int end, long long int searching_for) {
	long long int mid = (start + end) / 2;
	if (vector[mid] == searching_for) return mid;
	if (vector[mid] < searching_for) return bsearch(vector, start, mid, searching_for);
	else return bsearch(vector, mid, end, searching_for);
}

int main() {
	long long int v, q, i, tmp, tmp_pos;

	while(scanf("%lld %lld", &v, &q) != EOF) {
		long long int values[v];
		long long int queries[q];

		for(i = 0; i < v; i++) {
			scanf("%lld", &values[i]);
		}

		for(i = 0; i < q; i++) {
			scanf("%lld", &tmp);
			tmp_pos = bsearch(values, 0, v - 1, tmp);
			
			while(tmp_pos > 0 && values[tmp_pos - 1] == tmp) tmp_pos--;
			queries[i] = tmp_pos;
		}

		for (i = 0; i < q; i++) printf("%lld\n", queries[i]);

	}

	return 0;
}
