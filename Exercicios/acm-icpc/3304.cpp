#include <cstdio>
#include <utility>
using namespace std;

int matrix[9][9];

pair<int, int> newCoord(pair<int, int> cur) {
	int i = cur.first, j = cur.second;

	if (i % 3 == 2 && j % 3 == 2) {
		// New block
		if (j == 8) return make_pair(i+1, 0);
		else return make_pair(i-2, j+1); 

	} else {
		// Same block
		if (j % 3 == 2) return make_pair(i+1, j-2);
		else return make_pair(i, j+1);

	}
}

bool solve(pair<int, int> coord) {
	if (coord.first >= 9 || coord.second >= 9) return true;
	int i = coord.first, j = coord.second;

	if (matrix[i][j] > 0) return solve(newCoord(coord));
	else {
		bool available[10], solved = false;

		for (int k = 0; k <= 9; k++) 
			available[k] = true;
		
		available[0] = false;

		for (int k = 0; k < 9; k++) {
			available[matrix[i][k]] = false;
			available[matrix[k][j]] = false;
		}

		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				available[matrix[i - i%3 + k][j - j%3 + l]] = false;
			}
		}

		for (int k = 1; !solved && k <= 9; k++) {
			if (!available[k]) continue;

			matrix[i][j] = k;
			solved = solve(newCoord(coord));
		}

		if (!solved) matrix[i][j] = 0;

		return solved;
	}
}

int main() {
	int n, a;
	char c;

	scanf("%d", &n);

	while(n--) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				scanf(" %c", &c);
				matrix[i][j] = c - '0';
			}

		solve(make_pair(0, 0));

		for(int i = 0; i < 9; i++, printf("\n"))
			for (int j = 0; j < 9; j++)
				printf("%d", matrix[i][j]);
		
		printf("\n");
	}

	return 0;
}
