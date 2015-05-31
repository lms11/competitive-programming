#include <stdio.h>

int main() {
	char strings[110][11];
	int nt, nw, i, j, i_english;

	scanf("%d", &nt);
	
	for(i = 0; i < nt; i++) {
		scanf("%d", &nw);

		i_english = -1;

		for(j = 0; j < nw; j++) {
			scanf("%s", &strings[j]);
			if (strings[j][0] != '#') i_english = j;
		}

		for(j = i_english + 1; j < nw; j++) { 
			printf("%s", strings[j]);
			if ((i_english == -1 && j < nw-1) || i_english != -1) printf(" ");
		}
		if (i_english != -1) { 
			printf("%s", strings[i_english]);
			if (i_english > 0) printf(" ");
		}
		for(j = 0; j < i_english; j++) {
			printf("%s", strings[j]);
			if (j < i_english-1) printf(" ");
		}

		printf("\n");
	}

	return 0;
}
