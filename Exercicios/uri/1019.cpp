#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int valor;
	scanf("%d", &valor);
	printf("%d:%d:%d\n", valor/3600, (valor%3600)/60, ((valor%3600)%60));
    return 0;
}