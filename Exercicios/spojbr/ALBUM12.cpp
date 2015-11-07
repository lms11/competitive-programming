#include <cstdio>

int main() {
	int W, H, w1, h1, w2, h2;

	scanf("%d %d %d %d %d %d", &W, &H, &w1, &h1, &w2, &h2);

	if (
		(h2 <= H - h1 && w2 <= W && w1 <= W) ||
		(w2 <= H - h1 && h2 <= W && w1 <= W) ||
		(h2 <= W - w1 && w2 <= H && h1 <= H) ||
		(w2 <= W - w1 && h2 <= H && h1 <= H) ||
		(h2 <= W - h1 && w2 <= H && w1 <= H) ||
		(w2 <= W - h1 && h2 <= H && w1 <= H) ||
		(h2 <= H - w1 && w2 <= W && h1 <= W) ||
		(w2 <= H - w1 && h2 <= W && h1 <= W))
		printf("S\n");
	else
		printf("N\n");

	return 0;
}