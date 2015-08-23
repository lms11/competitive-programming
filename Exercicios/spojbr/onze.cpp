#include <iostream>
using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

int main() {
        string num;
        long long int soma;
        int i, sinal;
        while(cin >> num && num != "0") {
                sinal = 1;
                soma = 0;
                for(i = 0; i < num.length(); i++) {
                        soma += sinal * (num[i] - '0');
                        sinal *= -1;
                }

                if (soma == 0 || soma % 11 == 0) printf("%s is a multiple of 11.\n", num.c_str());
                else printf("%s is not a multiple of 11.\n", num.c_str());
        }

        return 0;
}
