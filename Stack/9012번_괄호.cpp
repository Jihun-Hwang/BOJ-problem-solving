// 문제 원본 : https://www.acmicpc.net/problem/9012
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numOfPS;
	vector<string> result;

	cin >> numOfPS;

	while (numOfPS--) {
		char PS[50];
		vector<char> stack;
		bool isSolved = true;

		scanf("%s", &PS);

		for (int i = 0; PS[i] != '\0'; i++) {
			if (PS[i] == '(') {
				stack.push_back('('); continue;
			}
			// 아래는 ')'인 경우
			if (!stack.empty()) {
				stack.pop_back();
			}
			else {
				isSolved = false;
				break;
			}
		}

		if (isSolved && stack.empty()) {
			result.push_back("YES\n");
		}
		else {
			result.push_back("NO\n");
		}
	}

	for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter;
	}

	return 0;
}
