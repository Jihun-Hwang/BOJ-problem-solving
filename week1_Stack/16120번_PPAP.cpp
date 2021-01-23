// 문제 원본 https://www.acmicpc.net/problem/16120
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<char> stack;
	string inputSeq;
	cin >> inputSeq;

	for (int i = 0; inputSeq[i] != '\0'; i++) {
		stack.push_back(inputSeq[i]);

		int len = stack.size();
		if (len >= 4 && stack[len - 4] == 'P' && stack[len - 3] == 'P' && stack[len - 2] == 'A' && stack[len - 1] == 'P') {
			stack.pop_back(); stack.pop_back(); stack.pop_back(); stack.pop_back();
			stack.push_back('P');
		}
	}

	if (stack.size() == 1 && stack[0] == 'P') cout << "PPAP";
	else cout << "NP";

	return 0;
}
