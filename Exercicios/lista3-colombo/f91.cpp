#include <iostream>
using namespace std;

int f91(int n) {
	if (n <= 100) return f91(f91(n + 11));
	else return n - 10;
}

int main() {
	int number;

	while (cin >> number && number != 0) {
		cout << "f91(" << number << ") = " << f91(number) << "\n";
	}

	return 0;
}
