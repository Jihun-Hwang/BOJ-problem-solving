// 문제 링크 https://www.acmicpc.net/problem/1992
#include <iostream>

using namespace std;

int board[65][65];

void solve(int N, int y, int x) {
    if (N == 1) {
        cout << board[y][x];
        return;
    }

    int pivot = board[y][x];
    int half = N / 2;

    for (int i = y; i < y + N; i++) {      // 2중 for문은 해당 구역만을 검사함
        for (int j = x; j < x + N; j++) {
            if (pivot == board[i][j]) continue;

            cout << "(";
            solve(half, y, x);
            solve(half, y, x + half);
            solve(half, y + half, x);
            solve(half, y + half, x + half);
            cout << ")";
            return;
        }
    }
    //현재 구역의 모든 요소가 같은 경우
    cout << pivot;

    return;
}

int main() {
    int N;
    string line;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    if (N == 1) {
        cout << "(" << board[0][0] << ")";
        return 0;
    }

    solve(N, 0, 0);

    return 0;
}