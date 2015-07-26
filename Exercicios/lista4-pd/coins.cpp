#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef unsigned long long int myInt;

map<myInt, myInt> mem; 

myInt calc(myInt a) {
	/* Verifica se já foi calculado. Se sim, retorna ele */
	if (mem.count(a) > 0) return mem[a];

	if (a <= 1)
		mem.insert(pair<myInt, myInt>(a, a));
	else 
		mem.insert(pair<myInt, myInt>( a, max(a, calc(a/2) + calc(a/3) + calc(a/4)) ));

	return mem[a];
}


int main() {
	myInt n;

	while(cin >> n) {
		cout << calc(n) << endl;
	}

	return 0;
}
