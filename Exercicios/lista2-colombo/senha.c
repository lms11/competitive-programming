/* Problema: http://br.spoj.com/problems/SENHA/ */

#include <stdio.h>

int chartoi(int c) {
	return 2 * (c - 'A');
}

int main() {
	char senhas[10][6];
	int comb[10][10];
	int poss[6][2];
	int i, j, n, t = 1;

	while(scanf("%d", &n), n > 0) {
		for(i = 0; i < n; i++) {
			scanf("%d %d %d %d %d %d %d %d %d %d %c %c %c %c %c %c",
				&comb[i][0], &comb[i][1], &comb[i][2], 
				&comb[i][3], &comb[i][4], &comb[i][5], 
				&comb[i][6], &comb[i][7], &comb[i][8], &comb[i][9], 
				&senhas[i][0], &senhas[i][1], &senhas[i][2],
				&senhas[i][3], &senhas[i][4], &senhas[i][5]);
		}

		for (i = 0; i < 6; i++) {
			poss[i][0] = comb[0][chartoi(senhas[0][i])];
			poss[i][1] = comb[0][chartoi(senhas[0][i]) + 1];
		}

		for (i = 1; i < n; i++) {
			for (j = 0; j < 6; j++) {
				if ((poss[j][0] != comb[i][chartoi(senhas[i][j])]) && (poss[j][0] != comb[i][chartoi(senhas[i][j]) + 1])) poss[j][0] = -1;
				else if ((poss[j][1] != comb[i][chartoi(senhas[i][j])]) && (poss[j][1] != comb[i][chartoi(senhas[i][j]) + 1])) poss[j][1] = -1;

			}
		}


		printf("Teste %d\n", t++);
		for (i = 0; i < 6; i++) if (poss[i][0] != -1) printf("%d ", poss[i][0]); else printf("%d ", poss[i][1]);
		printf("\n\n");
	}
	
	return 0;
}
