// 문제 링크 https://www.acmicpc.net/problem/19236
#include <iostream>
#include <tuple>

using namespace std;

void solve(int, int, int); // {y, x, 현재까지 합}
void moveFish();
void backupStat(tuple<int, int, int> fromFish, int fromBoard, tuple<int, int, int> toFish, int toBoard);
void changeStat(int y, int x, int ny, int nx, bool isEating, int fishNum);
void swapFish(tuple<int, int, int, bool>& A, tuple<int, int, int, bool>& B);

tuple<int, int, int, bool> fish[17]; // 1부터 사용 {y, x, dir, isAlive}
int board[4][4]; // fish 번호만 저장, 먹혔으면 0, 상어 위치이면 -1
int ans;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // index 0 사용안함
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void backupStat(tuple<int, int, int, bool> fromFish[17], int fromBoard[][4],
	tuple<int, int, int, bool> toFish[17], int toBoard[4][4]) {
	for (int i = 1; i <= 16; i++) {
		toFish[i] = { get<0>(fromFish[i]), get<1>(fromFish[i]), get<2>(fromFish[i]), get<3>(fromFish[i]) };
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			toBoard[i][j] = fromBoard[i][j];
		}
	}
}

void solve(int y, int x, int curSum, int curDir) {
	ans = max(ans, curSum);

	tuple<int, int, int, bool> tmpFish[17];
	int tmpBoard[4][4];

	// 물고기 이동
	backupStat(fish, board, tmpFish, tmpBoard);
	moveFish();

	// 상어 이동(최대 3번 가능) : backtrack
	for (int offset = 1; offset <= 3; offset++) {
		int ny = y + dy[curDir] * offset;
		int nx = x + dx[curDir] * offset;

		if (ny < 0 || nx < 0 || ny > 3 || nx > 3) continue;
		if (board[ny][nx] == 0) continue; // 이미 먹음

		int nextDir = get<2>(fish[board[ny][nx]]);
		int nextFishNum = board[ny][nx];

		changeStat(y, x, ny, nx, true, nextFishNum);
		solve(ny, nx, curSum + nextFishNum, nextDir);
		changeStat(y, x, ny, nx, false, nextFishNum);
	}

	// 물고기 이동 복구
	backupStat(tmpFish, tmpBoard, fish, board);
}

void moveFish() {
	for (int fnum = 1; fnum <= 16; fnum++) {
		if (get<3>(fish[fnum]) == false) continue;

		int y = get<0>(fish[fnum]);
		int x = get<1>(fish[fnum]);
		int dir = get<2>(fish[fnum]);

		int ny, nx;

		while (true) {  // 올바른 다음 위치를 찾는 과정
			ny = y + dy[dir];
			nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny > 3 || nx > 3 || board[ny][nx] == -1) {
				if ((++dir) == 9) dir = 1;
				continue;
			}
			break;
		}

		if (board[ny][nx] == 0) {
			get<0>(fish[fnum]) = ny;
			get<1>(fish[fnum]) = nx;
			get<2>(fish[fnum]) = dir;
			board[ny][nx] = fnum;
			board[y][x] = 0;
			continue;
		}
		// 두 물고기를 swap 해야 하는 경우
		swapFish(fish[fnum], fish[board[ny][nx]]);
		swap(board[y][x], board[ny][nx]);
		get<2>(fish[fnum]) = dir;
	}
}

void swapFish(tuple<int, int, int, bool>& A, tuple<int, int, int, bool>& B) {
	// 죄표 정보만 바꿔줘야함. 방향과 먹혔는지 정보는 바꾸면 안됌
	int tmpY = get<0>(A);
	int tmpX = get<1>(A);
	A = { get<0>(B), get<1>(B), get<2>(A), get<3>(A) };
	B = { tmpY, tmpX, get<2>(B), get<3>(B) };
}

void changeStat(int y, int x, int ny, int nx, bool isEating, int fishNum) {
	if (isEating) { // 상어 위치 변경
		board[y][x] = 0;
		board[ny][nx] = -1; // 상어 위치를 -1로 마킹
		get<3>(fish[fishNum]) = false;
	}
	else { // 다시 롤백인 경우
		board[y][x] = -1;
		board[ny][nx] = fishNum;
		get<3>(fish[fishNum]) = true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num, dir;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> num >> dir;
			fish[num] = { y, x, dir, true };
			board[y][x] = num;
		}
	}

	int firstFishNum = board[0][0];
	board[0][0] = -1; // 상어를 위치시킴
	get<3>(fish[firstFishNum]) = false; // isAlive = false
	solve(0, 0, 0 + firstFishNum, get<2>(fish[firstFishNum]));  // (0, 0, sum, dir) 먹힘으로 시작
	cout << ans;

	return 0;
}