// 문제 원본 https://www.acmicpc.net/problem/2606
// 일반 BFS + 그래프이론(행렬(2차원배열)방식)
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numVertex, numCon;  // vertex개수, 연결 개수
int board[101][101];    // 전역변수는 초기화 안하면 자동으로 0 으로 초기화
bool visited[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int u, v, result = 0;
	cin >> numVertex >> numCon;
	for (int i = 1; i <= numCon; i++) {
		cin >> u >> v;
		board[u][v] = board[v][u] = 1;
	}

	queue<int> Q;
	visited[1] = true;
	Q.push(1);

	while (!Q.empty()) {
		int curPos = Q.front(); Q.pop();

		for (int i = 1; i <= numVertex; i++) {
			if (!visited[i] && board[curPos][i] == 1) {
				visited[i] = true;
				Q.push(i);
				result++;
			}
		}
	}

	cout << result;

	return 0;
}
