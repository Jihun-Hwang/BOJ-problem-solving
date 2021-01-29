// 문제 원본 https://www.acmicpc.net/problem/2146
#include <bits/stdc++.h>

using namespace std;
void setAreaLabel();
int findDistance(int);

int Map[100][100];
bool visited[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int minDist = 0x7FFFFFFF;  // answer, 최대 한변이 100이므로 최대 거리는 10000일 것
int labelNum = 1;     // 초기 구역 라벨은 1부터 시작

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) Map[i][j] = -1;
		}
	}

	setAreaLabel();  // 같은 섬에 위치한 점들을 1부터 라벨링

	for (int area = 1; area < labelNum - 1; area++) {
		memset(visited, false, sizeof(visited));
		minDist = min(minDist, findDistance(area));
	}

	cout << minDist;

	return 0;
}

int findDistance(int fromArea) {
	queue<pair<int, int>> Q;
	int curDist = 0;

	for (int i = 0; i < N; i++) { // 현재 영역에 대해서 마킹
		for (int j = 0; j < N; j++) {
			if (Map[i][j] != fromArea) continue;
			visited[i][j] = true;
			Q.push({ i, j });
		}
	}

	// BFS
	while (!Q.empty()) {
		int S = Q.size();  // size ?????
		for (int i = 0; i < S; i++) {
			int curY = Q.front().first;
			int curX = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = curY + dy[i];
				int nx = curX + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (Map[ny][nx] != 0 && Map[ny][nx] != fromArea) return curDist;

				if (visited[ny][nx] == false && Map[ny][nx] == 0) {
					Q.push({ ny, nx });
					visited[ny][nx] = true;
				}

			}
		}
		if (++curDist >= minDist) return 0x7FFFFFFF; // 지금까지의 최솟값보다 큼. (실패)
	}
}

void setAreaLabel() {
	// bfs시 방문 마킹을 하지 않으면 메모리 초과가 발생함
	bool visitedLabel[100][100] = { false, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] != -1) continue;

			// 아래는 map[i][j]가 -1인 경우(라벨링이 아직 안된경우)
			queue<pair<int, int>> curLableQ;
			curLableQ.push({ i, j });
			visitedLabel[i][j] = true;

			//영역 라벨링을 위한 BFS 시작
			while (!curLableQ.empty()) {
				int curY = curLableQ.front().first;
				int curX = curLableQ.front().second;

				Map[curY][curX] = labelNum;
				curLableQ.pop();

				for (int t = 0; t < 4; t++) {
					int ny = curY + dy[t];
					int nx = curX + dx[t];

					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (Map[ny][nx] != -1 || visitedLabel[ny][nx]) continue;

					curLableQ.push({ ny, nx });
					visitedLabel[ny][nx] = true;
				}
			}
			labelNum++; // 영역 갱신
		}
	}
}
