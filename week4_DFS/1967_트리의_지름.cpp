// 문제 링크 https://www.acmicpc.net/problem/1967
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
void dfs(int, int);

vector<pair<int, int>> adj[10001];  // {인접 점, 비용}
bool visited[10001];
int numNode, maxCost, lognestNode;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numNode;
	while (--numNode) {
		int parent, child, cost;
		cin >> parent >> child >> cost;
		adj[parent].push_back({ child, cost });
		adj[child].push_back({ parent, cost });
	}

	dfs(1, 0);            // 1번 노드(루트)로 부터 가장 먼 거리의 노드 구하기

	memset(visited, false, sizeof(visited));
	maxCost = 0;

	dfs(lognestNode, 0);  // 구한 점으로 부터 maxCost 구하기

	cout << maxCost;

	return 0;
}

void dfs(int curNode, int curCost) {  // 인접 점, 비용
	visited[curNode] = true;

	if (curCost > maxCost) {    // depth가 커질때만 값 갱신(후퇴할때에는 갱신하지 않음)
		maxCost = curCost;
		lognestNode = curNode;
	}

	for (auto adjPosPair : adj[curNode]) {
		if (visited[adjPosPair.first]) continue;
		dfs(adjPosPair.first, curCost + adjPosPair.second);
	}
}
