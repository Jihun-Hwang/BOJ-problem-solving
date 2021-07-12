// 문제 링크 https://www.acmicpc.net/problem/20058
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

void turning(int, int, int);
void solve();
void fineMaxSizebfs(int y, int x);
void checkAdj_and_Substract();

using namespace std;

int board[500][500];
bool visited[500][500]; // bfs용
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, Q, L, sum, maxSize, sizeBoard;
queue<int> level;

void turning(int y, int x, int len) {
	int sqare = len / 2;
	for (int numSqare = 0; numSqare < sqare; numSqare++) {
		int startY = y + numSqare;
		int startX = x + numSqare;
		int endY = y + len - 1 - numSqare;
		int endX = x + len - 1 - numSqare;

		vector<int> tmp;
		int tmpY = startY;
		int tmpX = endX - 1;
		int idx = 0;
		for (int i = startY; i < endY; i++) tmp.push_back(board[i][startX]);
		for (int i = startX; i < endX; i++) board[tmpY++][startX] = board[endY][i];
		for (int i = startY + 1; i <= endY; i++) board[endY][tmpX--] = board[i][endX];
		for (int i = endX; i >= startX + 1; i--) board[tmpY--][endX] = board[startY][i];
		for (int i = endX; i >= startX + 1; i--) board[startY][i] = tmp[idx++];
 	}
}

void fineMaxSizebfs(int y, int x) {
	queue<pair<int, int>> Q;
	Q.push({ y, x });
	visited[y][x] = true;
	int curSize = 1;

	while (!Q.empty()) {
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 1 || nx < 1 || ny > sizeBoard || nx > sizeBoard) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;

			Q.push({ ny, nx });
			visited[ny][nx] = true;
			curSize++;
		}
	}

	maxSize = max(maxSize, curSize);
}

void checkAdj_and_Substract() {
	queue<pair<int, int>> targetPoint;

	for (int i = 1; i <= sizeBoard; i++) {
		for (int j = 1; j <= sizeBoard; j++) {
			if (board[i][j] == 0) continue;

			int count = 0;
			for (int adjIndex = 0; adjIndex < 4; adjIndex++) {
				if (board[i + dy[adjIndex]][j + dx[adjIndex]] > 0)
					count++;
			}
			if (count < 3) targetPoint.push({ i, j });
		}
	}

	while (!targetPoint.empty()) {
		int y = targetPoint.front().first;
		int x = targetPoint.front().second;
		targetPoint.pop();

		board[y][x]--;
		sum--;
	}
}

void solve() {
	while (!level.empty()) {
		int curLevel = level.front(); level.pop();
		int pieceLen = pow(2, curLevel);

		for (int i = 1; i <= sizeBoard - pieceLen + 1; i += pieceLen) {
			for (int j = 1; j <= sizeBoard - pieceLen + 1; j += pieceLen) {
				turning(i, j, pieceLen);
			}
		}

		checkAdj_and_Substract();
	}

	for (int i = 1; i < sizeBoard; i++) {
		for (int j = 1; j < sizeBoard; j++) {
			if (board[i][j] == 0) continue;
			if (visited[i][j] == true) continue;
			fineMaxSizebfs(i, j);
		}
	}

	cout << sum << '\n' << maxSize;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tmp;

	cin >> N >> Q;
	for (int i = 1; i <= sizeBoard; i++) {
		for (int j = 1; j <= sizeBoard; j++) {
			cin >> tmp;
			sum += tmp;
			board[i][j] = tmp;
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> tmp;
		level.push(tmp);
	}

	sizeBoard = pow(2, N);
	solve();

	return 0;
}
