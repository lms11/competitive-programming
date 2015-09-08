#include <cstdio>
#include <stack>
using namespace std;

bool leftAssociative(char c) {
	return c != '^'; // only ^ is right-associative
}

int precedence(char c) {
	if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
	return 3;
}

void solve() {
	stack<char> s;
	char c;

	while(scanf("%c", &c) > 0 && c != '\n') {

		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			while (s.size() > 0 && s.top() != '(' && ((leftAssociative(c) && precedence(c) <= precedence(s.top())) || (!leftAssociative(c) && precedence(c) < precedence(s.top())))) {
				printf("%c", s.top());
				s.pop();
			}
			s.push(c);

		} else if (c == '(') {
			s.push(c);

		} else if (c == ')') {
			while(s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			
			}
			s.pop();

		} else {
			printf("%c", c);
		}
	}

	while(s.size() > 0) {
		printf("%c", s.top());
		s.pop();
	}
}

int main() {
	int t;

	scanf("%d ", &t);

	for (int x = 0; x < t; x++) {
		solve();
		printf("\n");
	}

	return 0;
}
