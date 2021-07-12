// 문제 링크 https://www.acmicpc.net/problem/10026
#include <iostream>
#include <queue>
#include <string.h> // memset

using namespace std;

void solve();
void bfs(int, int);

char board[100][100];
bool visited[100][100];
int N;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int y, int x) {
	queue<pair<int, int>> Q;
	Q.push({ y, x });
	visited[y][x] = true;

	while (!Q.empty()) {
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (visited[ny][nx]) continue;

			if (board[y][x] == board[ny][nx]) {
				visited[ny][nx] = true;
				Q.push({ ny, nx });
			}
		}
	}
}

void solve() {
	int ans_normal = 0, ans_abnormal = 0;

	for (int i = 0; i < N; i++) {  // 색맹이 아닌 사람에 대해 계산
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;

			bfs(i, j);
			ans_normal++;
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {  // 색맹이 아닌 사람에 대해 계산
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;

			bfs(i, j);
			ans_abnormal++;
		}
	}

	cout << ans_normal << " " << ans_abnormal;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			board[i][j] = tmp;
		}
	}

	solve();

	return 0;
}