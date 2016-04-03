#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	long long int a, b;

	cin >> a >> b;

	if (a < b) cout << "<" << endl; 
	else if (a > b) cout << ">" << endl;
	else cout << "=" << endl;

	return 0;
}
