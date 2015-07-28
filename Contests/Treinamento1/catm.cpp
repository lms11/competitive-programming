#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int rx, ry, ax, ay, bx, by;
	int t;

	scanf("%d %d %d", &n, &m, &t);

	while(t--) {
		scanf("%d %d %d %d %d %d", &rx, &ry, &ax, &ay, &bx, &by);

		if ((ax >= rx && bx >= rx) || (ax <= rx && bx <= rx) || (ay >= ry && by >= ry) || (ay <= ry && by <= ry))
			printf("YES\n");
		else {
			if (ax > bx) {
				swap(ax, bx);
				swap(ay, by);
			}

			if (ry < ay) {
				ay = n - ay;
				by = n - by;
				ry = n - ry;
			}

			if ((ry < (bx - rx)) || (ry < (rx - ax))) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}
