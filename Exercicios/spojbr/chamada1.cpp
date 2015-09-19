#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int n, k;
	set<string> s;

	scanf("%d %d", &n, &k);

	while(n--) {
		string a;
		cin >> a;
		s.insert(a);
	}

	set<string>::iterator it = s.begin();
	advance(it, k-1);

	cout << *it;
	return 0;
}
