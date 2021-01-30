// 문제 원본 https://www.acmicpc.net/problem/2206
// 3차원 BFS문제 유형. 최대 K층까지 올라갈 수 있으며 각 단계에서는 층을 올라가든가 유지할 수만 있음
#include <iostream>
#include <queue>
#include <string.h>  // memcpy, memset

using namespace std;
int bfs();

// dist : 마지막 공간(2)은 처음에 1공간(아직 벽을 안뿌순 상태)에서 움직이다가
// 가는 길에 벽을 한번 부쉈다면 0공간(벽을 이미 뿌순 상태)에서 움직이도록 하기위함
int dist[1001][1001][2];
string map[1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int numY, numX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numY >> numX;
	for (int i = 0; i < numY; i++) {
		cin >> map[i];
	}

	cout << bfs();

	return 0;
}

int bfs() {
	queue<pair<pair<int, int>, int>> Q; // 좌표와 그 좌표가 벽뿌수기가 가능한 곳(1)인지 마킹
	Q.push({ { 0, 0 }, 1 });
	dist[0][0][1] = 1;   // {0,0}에서 시작해서 벽을 아직 뿌수기 전인 공간에서 움직이기 시작

	while (!Q.empty()) {
		int curY = Q.front().first.first;
		int curX = Q.front().first.second;
		int isAvail = Q.front().second;   // 현재 좌표가 어느 공간에서 움직이는지(1이면 아직 안부순 공간)
		Q.pop();

		if (curY == numY - 1 && curX == numX - 1) { // 목적지 도착
			return dist[curY][curX][isAvail];
		}

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (nx < 0 || ny < 0 || nx >= numX || ny >= numY) continue;

			// 벽이고, 아직 부순적이 없다면 ( 경로 마다 한번만 실행될 것 )
			if (map[ny][nx] == '1' && isAvail == 1) {
				Q.push({ { ny, nx }, isAvail - 1 }); // 이번 단계에서 벽을 하나 부쉈다고 마킹
				dist[ny][nx][isAvail - 1] = dist[curY][curX][isAvail] + 1; // 부순 벽을 의미하는 공간으로 이동
			}
			// 벽이 아니고, 아직 지나간 적이 없는 경우
			if (map[ny][nx] == '0' && dist[ny][nx][isAvail] == 0) {
				Q.push({ { ny, nx }, isAvail });
				dist[ny][nx][isAvail] = dist[curY][curX][isAvail] + 1;
			}
		}
	}
	// 벽 하나를 부수고도 목적지 까지 못한 경우
	return -1;
}
