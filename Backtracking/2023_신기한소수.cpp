// 문제 링크 https://www.acmicpc.net/problem/2023
#include <iostream>

using namespace std;
void backtrack(int, int);
bool isPrime(int);

int N;               // 입력 <= 8

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	backtrack(0, 0);

	return 0;
}

void backtrack(int number, int size) {   // 현재까지 만들어진 수, 그 수의 자리수
	if (size == N) {
		cout << number << '\n';
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int curNum = number * 10 + i;
		if (!isPrime(curNum)) continue;

		backtrack(curNum, size + 1);
	}
}

bool isPrime(int val) {
	if (val <= 1) return false; // 짝수인 경우, 1인 경우는 소수 아님

	for (int i = 2; i <= val / 2; i++)  // 최소한 중간 값까지는 확인해줘야 함
		if (val % i == 0) return false;

	return true;
}
