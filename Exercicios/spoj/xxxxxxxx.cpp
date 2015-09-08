#include <cstdio>
#include <map>
using namespace std;

#define MAX 55000 
#define lli long long int

int valores[MAX];

bool visited(lli x, map<lli, int> *m) {
	return (*m)[x] == 1;
}

void visit(lli x, map<lli, int> *m) {
	(*m)[x] = 1;
}

lli sum(int a, int b) {
	map<lli, int> m;
	lli soma = 0;
	
	for (int x = a; x <= b; x++) {
		if (!visited(valores[x], &m)) {
			visit(valores[x], &m);
			soma += valores[x];
		}
	}

	return soma;
}

int main() {
	int n, a, b;
	char c;

	scanf("%d", &n);

	b = 1;
	while(n--) {
		scanf("%d", &a);
		valores[b++] = a;
	}

	scanf("%d", &n);

	while(n--) {
		scanf(" %c %d %d", &c, &a, &b);
		
		if (c == 'U') valores[a] = b;
		else printf("%lld\n", sum(a, b));
	}
	
	return 0;
}
