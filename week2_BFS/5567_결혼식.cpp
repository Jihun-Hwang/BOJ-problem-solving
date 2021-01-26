// 문제 원본 https://www.acmicpc.net/problem/5567
// BFS(거리측정) + 그래프이론
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int board[501][501];   // index 1부터 사용
int dist[502];
bool visited[502];
int numF, len, curX, curY; //친구수, 리스트길이, 입력용x, y

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0; // 정답

	cin >> numF >> len;
	for (int i = 0; i < len; i++) {
		cin >> curX >> curY;
		board[curX][curY] = board[curY][curX] = 1;
	}

	queue<int> Q;
	Q.push(1);
	dist[1] = 1;  // 자기자신으로 부터 거리는 1이라고 가정
	visited[1] = true;

	while (!Q.empty()) {
		int curPos = Q.front(); Q.pop();

		for (int i = 2; i <= numF; i++) {
			if (visited[i] || board[curPos][i] != 1) continue;

			Q.push(i);
			dist[i] = dist[curPos] + 1;
			visited[i] = true;
		}
	}

	for (int i = 2; i <= numF; i++) {
		if (dist[i] == 2 || dist[i] == 3) ans++;
	}

	cout << ans;

	return 0;
}
