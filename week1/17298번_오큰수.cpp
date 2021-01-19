// 문제 원본 https://www.acmicpc.net/problem/17298
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numOfNGE; cin >> numOfNGE;
	vector<int> notFoundStack(numOfNGE), ans(numOfNGE, -1), inputSeq(numOfNGE);

	for (int i = 0; i < numOfNGE; i++) cin >> inputSeq[i];

	for (int i = 0; i < numOfNGE; i++) {
		while (!notFoundStack.empty() && inputSeq[notFoundStack.back()] < inputSeq[i]) {
			ans[notFoundStack.back()] = inputSeq[i];
			notFoundStack.pop_back();
		}
		notFoundStack.push_back(i);
	}

	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}
