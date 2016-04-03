#include <iostream>
#include <cmath>
using namespace std;

int numZeroes(long long int a) {
	bool x = false;
	int num = 0;

	if (a == 1) return 0;
	else if (a > 1 && a < 10) return -1;

	while(!x && a > 1) {
		if (a % 10 != 0 && a > 9) x = true;
		else {
			num++;
			a /= 10;
		}
	}

	if (x) return -1;
	else return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, x, y, z;
	bool hasZero = false;
	long long int numOfZeroes = 0;

//	scanf("%d", &n);
	cin >> n;
	
	z = 3;
	for (int i = 0; i < n; i++) {
		// scanf("%d", &x);
		cin >> x;

		if (x == 0) hasZero = true;
		else {
			y = numZeroes(x);
		
			if (y == -1) z = x;
			else numOfZeroes += y;
		}
	}

	if (hasZero) cout << "0" << endl; //printf("0\n");
	else {
		// printf("%d", z);
		cout << z;
		for (long long int i = 0; i < numOfZeroes; i++) cout << "0"; //printf("0");
		cout << endl; //printf("\n");
	}

	return 0;
}
