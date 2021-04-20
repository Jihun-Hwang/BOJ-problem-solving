// 문제 링크 https://www.acmicpc.net/problem/20057
#include <iostream>

using namespace std;

void solve();
void calSpreadVal(int, int, int);

int board[503][503];
bool visited[503][503];
int N;

int dy[4] = { 0, 1, 0,- 1 };
int dx[4] = { -1, 0, 1, 0 };

void solve() {
	int fromY = N / 2 + 2;
	int fromX = fromY;
	visited[fromY][fromX] = true;

	// 방향 정의 : 0:왼쪽, 1:아래, 2:오른쪽, 3:위쪽
	int dir = 0;

	while (true) {
		dir = dir % 4;

		int toY = fromY + dy[dir];
		int toX = fromX + dx[dir];
		if (toY == 2 && toX == 1) break;
		visited[toY][toX] = true;

		calSpreadVal(toY, toX, dir);

		int nextDir = (dir + 1) % 4;

		int nextY = toY + dy[nextDir];
		int nextX = toX + dx[nextDir];
		if (!visited[nextY][nextX]) {
			dir++;
		}

		fromY = toY;
		fromX = toX;
	}
	// 바깥 계산
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N + 4; j++) {
			ans += board[i][j];
		}
	}
	for (int i = N + 2; i < N + 4; i++) {
		for (int j = 0; j < N + 4; j++) {
			ans += board[i][j];
		}
	}
	for (int i = 2; i <= N + 1; i++) {
		for (int j = 0; j < 2; j++) {
			ans += board[i][j];
		}
	}
	for (int i = 2; i <= N + 1; i++) {
		for (int j = N + 2; j < N + 4; j++) {
			ans += board[i][j];
		}
	}
	cout << ans;
}

void calSpreadVal(int y, int x, int dir) {
	int curVal = board[y][x];
	int sevenVal = curVal * 0.07;
	int tenVal = curVal * 0.1;
	int fiveVal = curVal * 0.05;
	int twoVal = curVal * 0.02;
	int oneVal = curVal * 0.01;
	int aVal = curVal - (2 * (sevenVal + tenVal + twoVal + oneVal) + fiveVal);

	switch (dir){
	case 0:
		board[y - 1][x] += sevenVal;
		board[y + 1][x] += sevenVal;
		board[y - 1][x - 1] += tenVal;
		board[y + 1][x - 1] += tenVal;
		board[y - 2][x] += twoVal;
		board[y + 2][x] += twoVal;
		board[y - 1][x + 1] += oneVal;
		board[y + 1][x + 1] += oneVal;
		board[y][x - 2] += fiveVal;
		board[y][x - 1] += aVal;
		break;
	case 1:
		board[y][x - 1] += sevenVal;
		board[y][x + 1] += sevenVal;
		board[y + 1][x - 1] += tenVal;
		board[y + 1][x + 1] += tenVal;
		board[y][x - 2] += twoVal;
		board[y][x + 2] += twoVal;
		board[y - 1][x - 1] += oneVal;
		board[y - 1][x + 1] += oneVal;
		board[y + 2][x] += fiveVal;
		board[y + 1][x] += aVal;
		break;
	case 2:
		board[y - 1][x] += sevenVal;
		board[y + 1][x] += sevenVal;
		board[y - 1][x + 1] += tenVal;
		board[y + 1][x + 1] += tenVal;
		board[y - 2][x] += twoVal;
		board[y + 2][x] += twoVal;
		board[y - 1][x - 1] += oneVal;
		board[y + 1][x - 1] += oneVal;
		board[y][x + 2] += fiveVal;
		board[y][x + 1] += aVal;
		break;
	case 3:
		board[y][x + 1] += sevenVal;
		board[y][x - 1] += sevenVal;
		board[y - 1][x + 1] += tenVal;
		board[y - 1][x - 1] += tenVal;
		board[y][x - 2] += twoVal;
		board[y][x + 2] += twoVal;
		board[y + 1][x - 1] += oneVal;
		board[y + 1][x + 1] += oneVal;
		board[y - 2][x] += fiveVal;
		board[y - 1][x] += aVal;
		break;
	}
	board[y][x] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tmpVal;
	cin >> N;
	for (int i = 2; i < N + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			cin >> tmpVal;
			board[i][j] = tmpVal;
		}
	}

	solve();

	return 0;
}