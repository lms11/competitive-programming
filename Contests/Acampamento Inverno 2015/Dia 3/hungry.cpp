#include <iostream>
using namespace std;

int main() {
	long long int n, i;

	cin >> n;

	for(i = 0; i < n; i++) {
		cout << i+(9999999-n) << " ";
	}

	return 0;
}