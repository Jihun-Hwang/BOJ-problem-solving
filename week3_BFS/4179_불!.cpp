// 문제 링크 https://www.acmicpc.net/problem/4179
// reference : 바킹독
// BFS
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h> // memcpy
#include <algorithm> // fill

using namespace std;

string board[1001];
int fireDist[1001][1001];  // 불의 전파 시간
int dist[1001][1001];      // 지훈이의 이동 시간
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C;                  // 가로(행), 세로(열)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		fill(fireDist[i], fireDist[i] + C, -1);
		fill(dist[i], dist[i] + C, -1);
	}

	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	queue<pair<int, int>> fireQ;
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				fireQ.push({ i, j });
				fireDist[i][j] = 0; // 불 전파 시작점
			}
			else if (board[i][j] == 'J') {
				Q.push({ i, j });
				dist[i][j] = 0; // 지훈이 시작 위치
			}
		}
	}

	while (!fireQ.empty()) { // 불에 대한 BFS(각 지점당 불의 전파 시간 마킹)
		int curY = fireQ.front().first;
		int curX = fireQ.front().second;
		fireQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (nx < 0 || ny < 0 || ny >= R || nx >= C) continue;
			if (board[ny][nx] == '#' || fireDist[ny][nx] >= 0) continue;

			fireDist[ny][nx] = fireDist[curY][curX] + 1;
			fireQ.push({ ny, nx });
		}
	}

	while (!Q.empty()) {
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (nx < 0 || ny < 0 || nx >= C || ny >= R) { // 탈출 조건
				cout << dist[curY][curX] + 1;
				return 0;
			}

			if (board[ny][nx] == '#' || dist[ny][nx] >= 0) continue;
			if (fireDist[ny][nx] != -1 &&                 // 불이 전파될수 있는 곳이면서
				dist[curY][curX] + 1 >= fireDist[ny][nx]) // 지훈이보다 먼저 전파될수 있다면
				continue;

			Q.push({ ny, nx });
			dist[ny][nx] = dist[curY][curX] + 1;
		}

	}

	cout << "IMPOSSIBLE"; // BFS를 모두 돌때까지 탈출조건을 찾지 못함.

	return 0;
}
