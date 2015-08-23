#include <iostream>
using namespace std;

int fatorial(int x, int cur) {
	if (x > 1) return fatorial(x - 1, cur * x);
	return cur;
}

int main() {
	int number;

	while (cin >> number) {
		if (number > 12) continue;
		cout << fatorial(number, 1) << endl;
	}

	return 0;
}
