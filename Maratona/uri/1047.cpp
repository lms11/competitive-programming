#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int b_hour, b_min, e_hour, e_min, diff;
	scanf("%d %d %d %d", &b_hour, &b_min, &e_hour, &e_min);
	diff = (e_hour - b_hour) * 3600 + (e_min - b_min) * 60;
	if (diff == 0) printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
	else if (diff < 0) printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 24 + diff/3600, (diff%3600)/60 == 0 ? 0 : 60+(diff%3600)/60);
	else printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", diff/3600, (diff%3600)/60);
    return 0;
}