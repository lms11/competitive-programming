#include <iostream>
using namespace std;

int main() {
	string text, sub_cur, sub_prev;
	int a, b, txtlen, found, substrlen;

	while(cin >> text) {
		b = 2;
		txtlen = text.length();

		while (b <= txtlen) {
			found = 1;
			if (txtlen % b != 0) {
				b++;
				continue;
			}

			substrlen = txtlen / b;
			sub_prev = text.substr(0, substrlen);

			for(a = 0; a < (txtlen - substrlen); a += substrlen) {
				sub_cur = text.substr(a + substrlen, substrlen);

				if (sub_prev != sub_cur) {
					found = 0;
					break;
				}
				
				sub_prev = sub_cur;
			}
			
			if (found == 1) { printf("%d\n", substrlen); break; }
			else b++;
		}
	}

	return 0;
}
