// 문제 링크 https://www.acmicpc.net/problem/2331
#include <iostream>

using namespace std;
void DFS(int);
int getNextValue(int);   // DFS에서 다음에 돌릴 숫자를 계산함
int getPowerNum(int);    // 한자리 숫자의 제곱수를 반환함

int visitedCount[1000000];
int num, power;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;

	cin >> num >> power;

	DFS(num);
	for (int i = 1; i < 1000000; i++) {
		if (visitedCount[i] != 1) continue;
		ans++;
	}

	cout << ans;

	return 0;
}

void DFS(int _num) {
	if (++visitedCount[_num] > 2) return;  // ?
	DFS(getNextValue(_num));
}

int getNextValue(int curVal) {
	int next = 0;
	while (curVal > 0) {
		next += getPowerNum(curVal % 10);
		curVal /= 10;
	}
	return next;
}

int getPowerNum(int val) {
	int poweredNum = val;
	for (int i = 1; i < power; i++) {
		poweredNum = poweredNum * val;
	}
	return poweredNum;
}
