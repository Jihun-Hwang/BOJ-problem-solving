// 문제 링크 https://www.acmicpc.net/problem/14503
#include <iostream>

using namespace std;

void clean();
pair<int, int> getNextPos();
void setNextDir();
bool setBackPos();

int board[53][53];    // 최대 50
int height, width, curRow, curCol, dir; // board의 높이, 폭, 청소기의 위치 (r, c), 방향
int ans = 1;          // 로봇 청소기가 청소한 칸의 개수, 시작점은 청소했다고 가정하고 시작

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> height >> width >> curRow >> curCol >> dir;
	for (int i = 0; i < height; i++) {      // 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 입력
		for (int j = 0; j < width; j++) {   // 1 : 벽, 0 : 빈칸
			int curVal;
			cin >> curVal;
			board[i][j] = curVal;
		}
	}

	clean();

	cout << ans;

	return 0;
}

void clean() {
	board[curRow][curCol] = 2;  // 2 : 이미 청소한 곳을 의미함

again :
	while (true) {
		for (int i = 0; i < 4; i++) {
			setNextDir();  // 왼쪽으로 방향 회전
			pair<int, int> nextPos = getNextPos();

			if (board[nextPos.first][nextPos.second] == 0) { // 왼쪽이 아직 청소하지 않은곳이라면
				// 아직 청소하지 않은 곳으로 이동
				curRow = nextPos.first;
				curCol = nextPos.second;

				// 정답 + 1, 해당칸은 청소한 곳으로 마킹
				ans++;
				board[curRow][curCol] = 2;  // 청소함을 마킹
				goto again;
			}
		}

		// 4방이 모두 막힌 상태인 경우
		if (!setBackPos())      // 뒤로 한칸 후진
			return;             // 뒤가 벽이라 후진도 할 수 없는 경우
	}
}

pair<int, int> getNextPos() {
	int row = curRow;
	int col = curCol;
	// dir (0 : 북쪽, 1 : 동쪽, 2 : 남쪽, 3 : 서쪽)
	switch (dir) {
		case 0: row = row - 1; break;   // break; 안해주면 오류남
		case 1: col = col + 1; break;
		case 2: row = row + 1; break;
		case 3: col = col - 1; break;
	}

	return { row, col };
}

void setNextDir() {
	if (dir == 0) dir = 3;
	else if (dir == 3) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 1) dir = 0;
}

bool setBackPos() {
	if (dir == 0) {
		if (board[curRow + 1][curCol] == 1) return false;  // 이미 청소한 칸인경우(2인경우)는 되돌아갈 수 있음
		curRow = curRow + 1;
	}
	else if (dir == 3) {
		if (board[curRow][curCol + 1] == 1) return false;
		curCol = curCol + 1;
	}
	else if (dir == 2) {
		if (board[curRow - 1][curCol] == 1) return false;
		curRow = curRow - 1;
	}
	else if (dir == 1) {
		if (board[curRow][curCol - 1] == 1) return false;
		curCol = curCol - 1;
	}

	return true;
}