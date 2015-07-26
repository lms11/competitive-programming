#include <stdio.h>
#include <string.h>

int main() {
	char in[10];
	int len, i, aux;
	long long int num, power = 1;

	while(1) {
		scanf(" %s", in);
		sscanf(in, "%d", &i);

		if (i == 0) break;

		len = strlen(in);
		num = 0;
		power = 1;

		for (i = 0; i < len/2; i++) {
			if (in[i] < in[len-i]) {
				num += ((int)in[i] * 10 - in[i-len]) * power;
				aux = 1;
				in[i-len-aux] += 1;

				while(in[i-len+aux] == ('9' + 1)) {
					in[i-len+aux] = '0';
					aux++;
					in[i-len-aux] += 1;
				}

			}
			else num += ((int)in[i] - in[i-len]) * power;

			power *= 10;
		}

		printf("%lld\n", num);
	}
}