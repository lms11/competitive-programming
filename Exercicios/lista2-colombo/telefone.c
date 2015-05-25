#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char converte(char c) {
	if (c == 'A' || c == 'B' || c == 'C' || c == 'a' || c == 'b' || c == 'c') return '2';
	if (c == 'D' || c == 'E' || c == 'F' || c == 'd' || c == 'e' || c == 'f') return '3';
	if (c == 'G' || c == 'H' || c == 'I' || c == 'g' || c == 'h' || c == 'i') return '4';
	if (c == 'J' || c == 'K' || c == 'L' || c == 'j' || c == 'k' || c == 'l') return '5';
	if (c == 'M' || c == 'N' || c == 'O' || c == 'm' || c == 'n' || c == 'o') return '6';
	if (c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'p' || c == 'q' || c == 'r' || c == 's') return '7';
	if (c == 'T' || c == 'U' || c == 'V' || c == 't' || c == 'u' || c == 'v') return '8';
	if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z' || c == 'w' || c == 'x' || c == 'y' || c == 'z') return '9'; 
	return c;
}

int main() {
	char c;

	while(scanf("%c", &c) != EOF) {
		printf("%c",converte(c));
	}

	return 0;
}
