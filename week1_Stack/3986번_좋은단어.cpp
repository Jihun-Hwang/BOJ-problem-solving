//  https://www.acmicpc.net/problem/3986
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	unsigned int numOfWord, resultNum = 0;
	string word = "";
	vector<char> stack;

	cin >> numOfWord;

	while (numOfWord--) {
		cin >> word;
		stack.push_back(word.at(0));

		for (int i = 1; i < word.length(); i++) {
			if ((!stack.empty()) && (stack[stack.size() - 1] == word.at(i))) {
				stack.pop_back();
			}
			else {
				stack.push_back(word.at(i));
			}
		}

		if (stack.empty()) resultNum++;
		stack.clear();
	}

	cout << resultNum;

	return 0;
}
