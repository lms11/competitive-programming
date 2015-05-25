#include <stdio.h>
#include <stdlib.h>

#define MAX 6000

struct typedef {
	char begin, end; // < is begin, > is end and . is cheese
} Link;

Link createLink(char begin, char end) {
	Link newLink = malloc(sizeof(Link));
	newLink.begin = begin;
	newLink.end = end;
	return newLink;
}

char convertChar(char c[]) {
	char res;
	if (c == "Entrada") res = '<';
	else if (c == "Saida") res = '>';
	else if (c[0] == '0') res = '.';
	else res = c[0];
	
	return res;
}

int main() {
	int i, n_points, n_links;
	Link links[MAX];
	char a[10], b[10];

	while(scanf("%d %d", &n_points, &n_links) != EOF) {
		
		for(i = 0; i < n_links; i++) {
			scanf("%s", &a);
			scanf("%s", &b);
			
			links[i] = createLink(convertChar(a), convertChar(b));
		}
		
		
	}

	return 0;
}
