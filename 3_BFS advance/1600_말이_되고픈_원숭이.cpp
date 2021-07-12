// 문제 원본 https://www.acmicpc.net/problem/1600
// 3차원 BFS유형. 층은 올라가거나 유지하는 것만 가능하면서 최대 층까지 도달하는 문제
#include <iostream>
#include <queue>
#include <string.h>  // memcpy, memset

using namespace std;
int bfs();

int board[201][201];
bool visited[201][201][30 + 2];    // 능력은 최대 30번 가능

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int knightDx[8] = { -1, -2, -2, -1, 2, 1, 2, 1 };
int knightDy[8] = { -2, -1, 1, 2, 1, 2, -1, -2 };
int numY, numX, K; // K : 최대 능력 사용 가능 횟수 < 30

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> K >> numX >> numY;  // 최대 능력횟수, 가로길이, 세로길이
	for (int i = 0; i < numY; i++) {
		for (int j = 0; j < numX; j++) {
			cin >> board[i][j];
		}
	}

	cout << bfs();

	return 0;
}

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> Q; // {y, x}, {현재까지의 능력 사용 횟수, 현재까지거리}
	Q.push({ { 0, 0 }, { 0, 0 } });  // {0,0}에서 시작, K값과 거리는 0부터 시작
	visited[0][0][0] = true; //{0,0}방문, 능력은 0인 시점에 방문함을 마킹

	while (!Q.empty()) {
		int curY = Q.front().first.first;
		int curX = Q.front().first.second;
		int knight = Q.front().second.first; // 직전까지 능력 사용횟수
		int dist = Q.front().second.second;  // 직전까지 이동한 횟수
		Q.pop();

		if (curY == numY - 1 && curX == numX - 1) {
			return dist;
		}
		// 아직 능력을 쓸 수 있는 경우
		if (knight < K) {
			for (int i = 0; i < 8; i++) {
				int ny = curY + knightDy[i];
				int nx = curX + knightDx[i];

				if (ny < 0 || nx < 0 || ny >= numY || nx >= numX) continue;
				if (board[ny][nx] == 1 || visited[ny][nx][knight + 1]) continue;

				Q.push({ { ny, nx }, { knight + 1, dist + 1} }); // 능력사용 횟수 +1
				visited[ny][nx][knight + 1] = true;
			}
		}
		// 능력을 사용하지 않는 경우(동시에 따져줌)
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || nx < 0 || ny >= numY || nx >= numX) continue;
			if (board[ny][nx] == 1 || visited[ny][nx][knight]) continue; // 능력을 안쓸것이기 때문에 knight임

			Q.push({ {ny, nx}, {knight, dist + 1} });
			visited[ny][nx][knight] = true;
		}
	}

	return -1;
}
