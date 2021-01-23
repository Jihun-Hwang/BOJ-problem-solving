// 문제 원본 https://www.acmicpc.net/problem/1874
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;                    // 수열의 길이
	int sequ[100000] = { 0, };    // 수열을 담을 배열
	vector<char> result;          // 결과(+, -)를 담을 배열
	vector<int> stack;
	int accessedTopValue = 1;     // stack에서 현재까지 접근된 최대 값

	// 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> sequ[i]; }

	// 연산 사작
	for (int i = 0; i < n; i++) {
		if (stack.empty() || (stack[stack.size() - 1] < sequ[i])) {
			for (; accessedTopValue <= sequ[i]; accessedTopValue++) {
				stack.push_back(accessedTopValue); result.push_back('+');
			}
			i--;
		}
		else if (stack[stack.size() - 1] == sequ[i]) {
			stack.pop_back(); result.push_back('-');
		}
		else {
			cout << "NO";
			goto end;
		}
	}

	// 결과 출력
	for (vector<char>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << '\n';
	}

end:
	return 0;
}
