#include <stdio.h>

int ff(int n, int ind) { int i;
	for (i=0; i < ind; i++)
		printf(" ");
	
	printf ("ff (%d, %d)\n", n, ind); 
	
	if (n == 1)
		return 1;
	
	if (n % 2==0)
		return ff(n/2, ind + 1);
	
	return ff((n-1)/2, ind +1) + ff((n+1)/2, ind +1);
}

int main() {
	ff(7, 0);

	return 0;
}
