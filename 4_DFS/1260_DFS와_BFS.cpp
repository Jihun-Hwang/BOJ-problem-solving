// 문제 링크 https://www.acmicpc.net/problem/1260
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;
void dfsRecursive(int);
void dfsStack(int);
void bfs(int);

int adj[1001][1001];           // 인덱스 0 사용안함
bool visited[1001];
int numVertex, numEdge, start;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numVertex >> numEdge >> start;
	for (; 0 < numEdge; numEdge--) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = adj[to][from] = 1;
	}

	dfsStack(start);          // dfs stack 방식
	//dfsRecursive(start);      // dfs 재귀 방식

	memset(visited, false, sizeof(visited));
	cout << '\n';

	bfs(start);

	return 0;
}

void dfsStack(int startPosition) {
	stack<int> S;
	S.push(startPosition);
	visited[startPosition] = true;

	cout << startPosition << ' ';

	while (!S.empty()) {
		int curPos = S.top(); S.pop();

		for (int adjPos = 1; adjPos <= numVertex; adjPos++) {
			if (visited[adjPos] || adj[curPos][adjPos] == 0) continue;

			cout << adjPos << ' ';
			visited[adjPos] = true;

			S.push(curPos);
			S.push(adjPos);

			break;
		}
	}
}

void dfsRecursive(int curPos) {
	visited[curPos] = true;
	cout << curPos << ' ';

	for (int adjPos = 1; adjPos <= numVertex; adjPos++) {
		if (adj[curPos][adjPos] == 0 || visited[adjPos]) continue;
		dfsRecursive(adjPos);
	}
}

void bfs(int startPosition) {
	queue<int> Q;
	Q.push(startPosition);
	visited[startPosition] = true;

	while (!Q.empty()) {
		int curPos = Q.front(); Q.pop();
		cout << curPos << ' ';

		for (int adjPos = 1; adjPos <= numVertex; adjPos++) { // 번호가 작은 것부터 방문
			if (adj[curPos][adjPos] == 0 || visited[adjPos]) continue;

			Q.push(adjPos);
			visited[adjPos] = true;
		}
	}
	cout << '\n';
}
