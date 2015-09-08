#include <cstdio>
#include "Sort.h"

int main() {
	Sort *s = new Sort(10, 8, 5, 6, 3, 2, 9, 0, -1, -15, 15);
	Sort::printv("Original:\t", s->getVector());
	Sort::printv("Insertion Sort:\t", s->selectionSort());
	cout << endl;

	return 0;
}