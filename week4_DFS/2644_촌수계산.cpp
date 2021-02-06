// 문제 링크 https://www.acmicpc.net/problem/2644
#include <iostream>

using namespace std;
void dfs(int, int);

int adj[101][101];
bool visited[101];
int numPeople, from, to, numRelation, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numPeople >> from >> to >> numRelation;
	for (; numRelation > 0; numRelation--) {
		int _from, _to;
		cin >> _from >> _to;
		adj[_from][_to] = adj[_to][_from] = 1;
	}

	dfs(from, 0);

	ans > 0 ? cout << ans : cout << -1;

	return 0;
}

void dfs(int curPos, int depth) {
	visited[curPos] = true;
	if (curPos == to) {
		ans = depth;
		return;
	}

	for (int adjPos = 1; adjPos <= numPeople; adjPos++) {
		if (visited[adjPos] || adj[curPos][adjPos] != 1) continue;
		// depth를 전역변수로 두고 DFS를 돌리면 잘못된 방향으로 갔을 경우에도 depth가 더해지는 로직 오류가 발생
		dfs(adjPos, depth + 1);
	}
}
