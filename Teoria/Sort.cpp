#include "Sort.h"
#include <limits>
#include <iostream>

Sort::Sort(int numArgs, ...) {
	va_list args;
	va_start(args, numArgs);

	for (int i = 0; i < numArgs; i++) {
		int value = va_arg(args, int);
		this->add(value);
	}

	va_end(args);
}

void Sort::add(int el) {
	this->v.push_back(el);
}

void Sort::printv(string prefix, vector<int> vec) {
	cout << prefix;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << " " << *it;
	cout << endl;
}

vector<int> Sort::getVector() {
	return this->v;
}

/*
	Insertion sort
	
	Descrição:
		Ordena um vetor no intervalo [0, n), começando com i = 0.
		Enquanto i != n, busca o menor valor no intervalo não-ordenado [i, n), coloca-o na i-ésima posição e incrementa i.
	
	Tempo de execução:	O(n^2)
*/

vector<int> Sort::selectionSort() {
	vector<int> res;
	res.insert(res.begin(), this->v.begin(), this->v.end()); // Copia "v" para "res", para ordernar em "res"
	int size = res.size(), min_i;

	for (int i = 0; i < size; i++) {
		min_i = i;

		for (int j = i+1; j < size; j++) {
			if (res[j] < res[min_i])
				min_i = j;
				 
		}

		int tmp = res[i];
		res[i] = res[min_i];
		res[min_i] = tmp;
	}

	return res;
}