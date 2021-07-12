// 문제 원본 https://www.acmicpc.net/problem/1926
// 기본 BFS 문제 (그래프이론x) - BFS응용2. 시작점이 여러 개인 유형(여러 시작점에서 모든 지점으로의 거리문제)
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;                 // n: 세로크기, m: 가로크기
int board[500][500];
bool visited[500][500];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int col = 0; col < n; col++)
		for (int row = 0; row < m; row++)
			cin >> board[col][row];

	int numOfPic = 0;  // 그림 개수
	int maxSize = 0;   // 크기가 가장 큰 그림사이즈

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || board[i][j] == 0) continue;

			numOfPic++;
			queue<pair<int, int>> Q;
			visited[i][j] = true;
			Q.push({ i, j });
			int curSize = 0;

			while (!Q.empty()) {
				curSize++;
				pair<int, int> curPos = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = curPos.first + dx[dir];
					int ny = curPos.second + dy[dir];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (board[nx][ny] != 1 || visited[nx][ny]) continue;

					visited[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
			//maxSize = max(maxSize, curSize);
			if (maxSize < curSize) maxSize = curSize;
		}
	}
	cout << numOfPic << '\n' << maxSize;

	return 0;
}
