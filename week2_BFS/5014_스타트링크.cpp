// 문제 원본 https://www.acmicpc.net/problem/5014
// BFS
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool visited[1000001];
int F, S, G, U, D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> Q;
	Q.push({ S, 0 });  // 현재 층수, 버튼누른 횟수
	visited[S] = true;

	int count, curPos;

	while (!Q.empty()) {
		curPos = Q.front().first;
		count = Q.front().second;
		Q.pop();

		if (curPos == G) {
			cout << count;
			return 0;
		}

		if (curPos + U <= F && !visited[curPos + U]) {
			visited[curPos + U] = true;
			Q.push({ curPos + U, count + 1 });
		}

		if (curPos - D > 0 && !visited[curPos - D]) {
			visited[curPos - D] = true;
			Q.push({ curPos - D, count + 1 });
		}
	}

	cout << "use the stairs";

	return 0;
}
