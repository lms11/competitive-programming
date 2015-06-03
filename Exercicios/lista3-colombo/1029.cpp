#include <iostream>
using namespace std;

int fibonacci(int number, int * num_calls) {
	(*num_calls)++;

	if (number <= 1) return number;
	else return fibonacci(number - 1, num_calls) + fibonacci(number - 2, num_calls);
}

int main() {
	int number, num_calls, value, i, v;

	cin >> v;

	for (i = 0; i < v; i++) {
		cin >> number;
		if (number < 1 || number > 39) continue;
		num_calls = -1;
		value = fibonacci(number, &num_calls);
		cout << "fib(" << number << ") = " << num_calls << " calls = " << value << endl;
	}	 

	return 0;
}
