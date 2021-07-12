// 문제 링크 https://www.acmicpc.net/problem/14502
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h> // memcpy

using namespace std;
void setWall(int, int&);
void BFS(int&);

int board[9][9];  // 크기가 작아 인접행렬 사용
int tempBoard[9][9];  // 벽을 3개 새워보기 전에 원본 board를 백업해둠
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int numX, numY;  // 가로 세로 크기 입력
int maxZero;
queue<pair<int, int>> baseQ;  // { y, x } 초기 바이러스만 담을 큐

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int zeroCount = 0;

	cin >> numY >> numX;
	zeroCount = numX * numY;  // 초기는 행렬 크기만큼 0의 개수를 설정
	for (int y = 0; y < numY; y++) {
		for (int x = 0; x < numX; x++) {
			cin >> board[y][x];
			if (board[y][x] != 0) zeroCount--; // 0이 아닐 때마다 감소시킴
			if (board[y][x] != 2) continue;
			baseQ.push({ y, x }); // 바이러스의 위치를 큐에 미리 담아둠.
		}
	} // zeroCount가 초기 0의 개수와 같은 상태일 것.

	for (int y = 0; y < numY; y++) {
		for (int x = 0; x < numX; x++) {
			if (board[y][x] != 0) continue;
			// 0 발견시 원본 board를 백업하고 0을 3개 넣어보기
			memcpy(tempBoard, board, sizeof(board));
			tempBoard[y][x] = 1; // 벽 세우기
			zeroCount--;   // 0인 자리에 벽을 세우고 0개수 감소
			setWall(1, zeroCount); // 벽을 3개까지 세우기 위한 재귀함수 호출
			tempBoard[y][x] = 0; // 원상 복구
			zeroCount++;
		}
	}

	cout << maxZero;

	return 0;
}

void setWall(int curCnt, int& zeroCountRef) {
	if (curCnt == 3) {
		BFS(zeroCountRef);
		return;
	}

	for (int y = 0; y < numY; y++) {
		for (int x = 0; x < numX; x++) {
			if (tempBoard[y][x] != 0) continue;

			tempBoard[y][x] = 1;
			zeroCountRef--;
			setWall(curCnt + 1, zeroCountRef);
			tempBoard[y][x] = 0;  //이 부분은 벽을 3개 세우고 BFS를 돌고 나서 수행될것.
			zeroCountRef++;
		}
	}
}

void BFS(int& zeroCountRef) { // 값이 2인 모든 지점을 시작으로 바이러스 전퍼
	int afterWall[9][9]; // 벽이 3개 세워진 뒤 상태
	memcpy(afterWall, tempBoard, sizeof(tempBoard));
	int curZeroCount = zeroCountRef; // 현재 bfs가 정답이 아닐 수 있으니 zeroCount는 백업
	queue<pair<int, int>> Q = baseQ; // 초기 바이러스가 담긴 큐에서 먼저 시작

	while (!Q.empty()) {
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (nx < 0 || ny < 0 || nx >= numX || ny >= numY) continue;
			if (afterWall[ny][nx] != 0) continue;

			afterWall[ny][nx] = 2; // 감염
			curZeroCount--;  // 감염되었으니 0의 개수 감소
			Q.push({ ny, nx });
		}
	}
	maxZero = max(curZeroCount, maxZero);
}
