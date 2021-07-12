// 문제  https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;
void bfs(int);   // bfs, dfs 둘다 가능
void dfs(int);

int adj[1001][1001];           // 인덱스 0 사용안함
bool visited[1001];
int numVertex, numEdge, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numVertex >> numEdge;

	for (; numEdge > 0; numEdge--) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = adj[to][from] = 1;
	}

	// 모든 점으로 부터 bfs 실행
	for (int start = 1; start <= numVertex; start++) {
		if (visited[start]) continue;
		dfs(start);   // 아직 방문을 안한 점에 대해 bfs 수행
	}

	cout << ans;

	return 0;
}

void dfs(int start) {
	stack<int> S;
	S.push(start);
	visited[start] = true;

	while (!S.empty()) {
		int from = S.top(); S.pop();

		for (int to = 1; to <= numVertex; to++) {
			if (adj[from][to] != 1 || visited[to]) // 연결되어 있지 않거나, 이미 방문했다면
				continue;

			visited[to] = true;
			S.push(to);
		}
	}
	ans++;    // 영역 개수 + 1
}

void bfs(int start) {
	queue<int> Q;
	Q.push(start);
	visited[start] = true;

	while (!Q.empty()) {
		int from = Q.front(); Q.pop();

		for (int to = 1; to <= numVertex; to++) {
			if (adj[from][to] != 1 || visited[to]) // 연결되어 있지 않거나, 이미 방문했다면
				continue;

			visited[to] = true;
			Q.push(to);
		}
	}
	ans++;    // 영역 개수 + 1
}
