#include <stdio.h>
#include <stdlib.h>

long long int binarySearch(long long int vet[], long long int value, long long int size)
{
     long long int min = 0;
     long long int max = size - 1;
     long long int mid;
     while (min <= max) 
     {
          mid = (min + max)/2;
          if (value == vet[mid])
               return mid;
          else if (value < vet[mid])
               max = mid-1;
          else
               min = mid+1;
     }
     return -1;
}

int main() {
	long long int n, q, i, tmp;

	scanf("%lld %lld", &n, &q);

	long long int values[n], queries[q];

	for (i = 0; i < n; i++) {
		scanf("%lld", &values[i]);
	}

	for (i = 0; i < q; i++) {
		scanf("%lld", &queries[i]);
	}

	for (i = 0; i < q; i++) {
		printf("%lld\n", binarySearch(values, queries[i], n));
	}

	return 0;
}
