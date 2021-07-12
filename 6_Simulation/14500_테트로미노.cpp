// 문제 링크 https://www.acmicpc.net/problem/14500
#include <iostream>

using namespace std;

void setMaxValueFromPivot(int, int);
void dfsLengthFour(int, int, int, int);
void setMaxValueForSpecialShape(int, int);

int board[503][503];    // 최대 500
int visited[503][503];
int height, width;
int ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> height >> width;
	for (int i = 0; i < height; i++) {    // 입력 받기
		for (int j = 0; j < width; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < height; i++) {   // 모든 점에 대해 인접한 4개의 점에 대해 최대값 구하기
		for (int j = 0; j < width; j++) {
			setMaxValueFromPivot(i, j);
		}
	}

	cout << ans;

	return 0;
}

void setMaxValueFromPivot(int y, int x) {
	visited[y][x] = true;
	dfsLengthFour(y, x, 1, board[y][x]);
	visited[y][x] = false;

	setMaxValueForSpecialShape(y, x);   // ㅗ, ㅓ, ㅜ, ㅏ : DFS로 할 수 없는 특수 케이스
}

void dfsLengthFour(int y, int x, int curLen, int curVal) {
	if (curLen == 4) {
		if (ans < curVal) ans = curVal;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;     // 전진
		dfsLengthFour(ny, nx, curLen + 1, curVal + board[ny][nx]);
		visited[ny][nx] = false;    // 후진
	}
}

void setMaxValueForSpecialShape(int y, int x) {
	//ㅗ (현재 좌표 ㅡ의 가운데)
	if (y >= 1 && x >= 1 && x < width - 1)
		ans = max(ans, board[y][x - 1] + board[y][x] + board[y - 1][x] + board[y][x + 1]);

	//ㅏ (현재 좌표 ㅣ의 가운데)
	if (y >= 1 && y < height - 1 && x < width - 1)
		ans = max(ans, board[y - 1][x] + board[y][x] + board[y][x + 1] + board[y + 1][x]);

	//ㅜ (현재 좌표 ㅡ의 가운데)
	if (x >= 1 && y < height - 1 && x < width - 1)
		ans = max(ans, board[y][x - 1] + board[y][x] + board[y + 1][x] + board[y][x + 1]);

	//ㅓ (현재 좌표 ㅣ의 가운데)
	if (y >= 1 && y < height - 1 && x >= 1)
		ans = max(ans, board[y - 1][x] + board[y][x] + board[y][x - 1] + board[y + 1][x]);
}