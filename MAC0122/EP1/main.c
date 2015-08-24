#include <stdio.h>
//#include <graphics.h>

char input[1000][1000];

int main(int argc, char **argv) {
	int t = 0;

	printf("INPUT:\n\n");
	printf("input_file: %s\n", argv[0]);
	printf("output_file: %s\n", argv[1]);
	printf("pix_per_unit: %s\n", argv[2]);
	printf("sample_type: %s\n", argv[3]);
	printf("sample_size: %s\n", argv[4]);

	while(scanf(" %s", input[t++]) != EOF);

	printf("\n\n\n\n");
	for (int i = 1; i <= t; ++i) {
		printf("Word %d: %s\n", i, input[i-1]);
	}

	return 0;
}