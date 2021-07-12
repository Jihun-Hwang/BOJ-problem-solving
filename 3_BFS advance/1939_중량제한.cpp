// 문제 원본 https://www.acmicpc.net/problem/1939
// BFS
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool BFS(int);

int numIland, numLine;   // 섬의 개수, 입력받을 연결정보 개수
int startPoint, endPoint; // 시작 섬, 끝 섬
vector<pair<int, int>> adj[100001];   // pair<인접 섬, cost>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> numIland >> numLine;

	int maxCost = 0;

	for (int i = 0; i < numLine; i++) {
		int factory1, factory2, tempCost;
		cin >> factory1 >> factory2 >> tempCost;
		adj[factory1].push_back({ factory2, tempCost });
		adj[factory2].push_back({ factory1, tempCost });
		maxCost = max(maxCost, tempCost);  // 입력 받으면서 최대 비용 계산
	}

	cin >> startPoint >> endPoint;

	int low = 0, high = maxCost;   // 0 ~ maxCost 에서 이진탐색 진행
	while (low <= high) {
		int mid = (low + high) / 2;

		// 이진탐색을 돌면서 startPoint -> endPoint의 최대 cost를 찾음.
		BFS(mid) == true ? low = mid + 1 : high = mid - 1;
	}

	cout << high;

	return 0;
}

bool BFS(int midCost) {   // midCost : startPoint -> endPoint의 최대 cost가 될 가능성이 있는 값
	bool visited[100001] = { false, };
	queue<int> Q;
	Q.push(startPoint);
	visited[startPoint] = true;

	while (!Q.empty()) {
		int curPos = Q.front(); Q.pop();

		if (curPos == endPoint) return true;

		for (auto curNextCostPair : adj[curPos]) {
			int nextPoint = curNextCostPair.first;
			int toNextCost = curNextCostPair.second;

			if (visited[nextPoint] or midCost > toNextCost) continue; //midCost가 해당 link의 cost보다 크다면

			Q.push(nextPoint);
			visited[nextPoint] = true;
		}
	}

	return false;
}
