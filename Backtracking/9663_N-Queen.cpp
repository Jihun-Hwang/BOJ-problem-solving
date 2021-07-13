// 문제 링크 https://www.acmicpc.net/problem/9663
#include <iostream>

using namespace std;
void backtrack(int);

bool isUsedCol[40];      // 세로위치에 퀸이 존재하는지 마킹
bool isUsedCross1[40];   // 각 대각선에 퀸이 존재하는지 마킹
bool isUsedCross2[40];
int N, ans;              // 1 ≤ N < 15  판 크기. 가로 또는 세로

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	backtrack(0);

	cout << ans;

	return 0;
}

void backtrack(int curRow) {
	if (curRow == N) {
		ans++;
		return;
	}

	for (int curCol = 0; curCol < N; curCol++) {
		if (isUsedCol[curCol] || isUsedCross1[curCol + curRow] || isUsedCross2[curRow - curCol + N - 1])
			continue;

		isUsedCol[curCol] = isUsedCross1[curCol + curRow] = isUsedCross2[curRow - curCol + N - 1] = true;
		backtrack(curRow + 1);
		isUsedCol[curCol] = isUsedCross1[curCol + curRow] = isUsedCross2[curRow - curCol + N - 1] = false;
	}
}
