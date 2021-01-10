//문제 원본 https://www.acmicpc.net/problem/1918 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	char exp[100];
	vector<char> stack;

	map<char, int> prio;
	prio['+'] = 1; prio['-'] = 1;
	prio['/'] = 2; prio['*'] = 2;
	prio['('] = 0;

	scanf("%s", &exp);

	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '(') {
			stack.push_back(exp[i]);
		}
		else if (isalpha(exp[i])) {
			cout << exp[i];
		}
		else if (exp[i] == ')') {
			while (stack.back() != '(') {
				cout << stack.back();
				stack.pop_back();
			}
			stack.pop_back();
		}
		else {
			while (!stack.empty() && prio[stack.back()] >= prio[exp[i]]) {
				cout << stack.back();
				stack.pop_back();
			}

			stack.push_back(exp[i]);
		}
	}

	while (!stack.empty()) {
		cout << stack.back();
		stack.pop_back();
	}

	return 0;
}
