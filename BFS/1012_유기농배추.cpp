// 문제 원본 https://www.acmicpc.net/problem/1012
// BFS응용2. 시작점이 여러 개인 유형
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int board[52][52];
bool visited[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int numX, numY, num배추;     // 가로, 세로, 배추개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int curX, curY; // 입력용 임시변수
	int numTC;
	cin >> numTC;

	while (numTC--) {
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));

		cin >> numX >> numY >> num배추;
		while (num배추--) {
			cin >> curX >> curY;
			board[curY][curX] = 1;
		}

		int ans = 0; // 구역 개수 (결과)

		// 가능한 모든 점에 대해 bfs 실행
		for (int y = 0; y < numY; y++) {
			for (int x = 0; x < numX; x++) {
				if (board[y][x] == 0 || visited[y][x]) continue;

				queue<pair<int, int>> Q;
				visited[y][x] = true;
				Q.push({ y, x });

				while (!Q.empty()) {
					pair<int, int> curPos = Q.front(); Q.pop();

					for (int i = 0; i < 4; i++) {
						int ny = curPos.first + dy[i];
						int nx = curPos.second + dx[i];

						if (nx < 0 || ny < 0 || nx >= numX || ny >= numY) continue;
						if (visited[ny][nx] || board[ny][nx] != 1) continue;

						visited[ny][nx] = true;
						Q.push({ ny, nx });
					}
				}
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
