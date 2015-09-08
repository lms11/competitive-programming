#include <cstdio>
#include <queue>
using namespace std;

struct Vend {
	int n, horas, index;
	bool operator < (const Vend& v) const {
		return (horas != v.horas) ? (horas > v.horas) : (index > v.index);
	}
};

Vend vendedores[1100];
int d[1100];

int main() {
	priority_queue<Vend> pq;
	int a, b, c;
	
	scanf("%d %d", &a, &b);

	for (int x = 0; x < a; x++) {
		vendedores[x].n = vendedores[x].horas = 0;
		vendedores[x].index = x;
		pq.push(vendedores[x]);
	}

	while (b--) {
		scanf("%d", &c);
		
		Vend v = pq.top();
		pq.pop();

		v.horas += c;
		v.n++;
		pq.push(v);
	}

	for(int x = 0; x < a; x++) {
		Vend v = pq.top();
		pq.pop();

		d[v.index] = v.n;
	}

	for (int x = 0; x < a; x++) {
		printf("%d %d\n", x+1, d[x]);
	}

	return 0;
}
