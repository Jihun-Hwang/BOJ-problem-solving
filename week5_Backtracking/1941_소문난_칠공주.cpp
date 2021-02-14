// 문제 링크 https://www.acmicpc.net/problem/1941
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
void backtrack(int, int, int);
bool isAdjArea();

char input[6][6];  // 5 x 5 행렬
bool visited[27];  // 25개 방문 여부
int ans;
vector<pair<int, int>> sevenGirls;  // 선택된 7명의 좌표 저장 -> 7개의 점이 인접점들인지 체크할떄 사용

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string line;

	for (int i = 0; i < 5; i++) {
		cin >> line;
		for (int j = 0; j < 5; j++)
			input[i][j] = line[j];
	}

	backtrack(0, 0, 0); // index, 이다솜수, 임도연수

	cout << ans;

	return 0;
}

void backtrack(int index, int lee, int lim) {
	if (lee + lim == 7) {
		if (lim > lee) return;
		if (isAdjArea())
			ans++;
		return;
	}

	for (int i = index; i < 25; i++) {    // i = index 부터 시작함으로써 중복 접근 방지
		if (visited[i]) continue;

		int curX = i % 5;
		int curY = i / 5;

		sevenGirls.push_back({ curY, curX });
		visited[i] = true;

		if (input[curY][curX] == 'Y')             // 상태공간트리 왼쪽노드 : 임도연 선택
			backtrack(i + 1, lee, lim + 1);
		else                                      // 상태공간트리 오른쪽노드 : 이다솜 선택
			backtrack(i + 1, lee + 1, lim);

		sevenGirls.pop_back();
		visited[i] = false;
	}
}

bool isAdjArea() { // bfs, 선택된 7개의 좌표가 서로 인접한지 확인
	queue<pair<int, int>> Q;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int count = 1;
	bool isFoundSevenGirls[7] = { false, };

	pair<int, int> start = sevenGirls[0];
	Q.push(start);
	isFoundSevenGirls[0] = true;  // sevenGirls vector의 0번째 소녀는 찾음

	while (!Q.empty()) {
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int k = 0; k < 7; k++) {
			if (isFoundSevenGirls[k]) continue;

			// k값이 sevenGirls에서 아직 찾지못한 소녀의 position(k값)이 정해짐
			for (int i = 0; i < 4; i++) {
				int ny = curY + dy[i];
				int nx = curX + dx[i];

				if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
				if (ny == sevenGirls[k].first && nx == sevenGirls[k].second) {
					Q.push({ ny, nx });
					isFoundSevenGirls[k] = true;
					count++;
				}
			}
		}
	}

	if (count == 7) return true;
	return false;
}
