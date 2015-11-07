#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	bool worked;

	scanf("%d", &n);

	while(n--) {
		stack<char> s;
		worked = true;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {

			if (str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '[') s.push(str.at(i));
			else {
				if (s.empty() ||
					(str.at(i) == ')' && s.top() != '(') ||
					(str.at(i) == ']' && s.top() != '[') ||
					(str.at(i) == '}' && s.top() != '{')) {
					worked = false;

				} else s.pop();
			}
		}

		if (worked && s.empty()) printf("S\n");
		else printf("N\n");
	}

	return 0;
}