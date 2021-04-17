// 문제 링크 https://www.acmicpc.net/problem/20056
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

void move();
void sum_and_split();
void solve();
pair<int, int> getNextPos(int y, int x, int speed, int dir);
void epilogue();

int N, M, K; // 격자 단면 크기, 파이어볼 개수, 이동횟수
vector<tuple<int, int, int, int, int>> board[52][52]; // index (0,0) 사용안함
vector<tuple<int, int, int, int, int>> fireball;   // {y, x, mass, speed, dir}

void move() {
    // fire ball 이동 후 board에 대입
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j].clear();
        }
    }

    for (int i = 0; i < fireball.size(); i++) {
        auto curBallInfo = fireball[i];
        int tmpY = get<0>(curBallInfo);
        int tmpX = get<1>(curBallInfo);
        int tmpMass = get<2>(curBallInfo);
        int tmpSpeed = get<3>(curBallInfo);
        int tmpDir = get<4>(curBallInfo);

        auto nextPos = getNextPos(tmpY, tmpX, tmpSpeed, tmpDir); // y, x, sppeed, dir

        // 초기화된 board에 삽입
        board[nextPos.first][nextPos.second].push_back({
            nextPos.first, nextPos.second, tmpMass, tmpSpeed, tmpDir });

        // 이동한 위치 갱신
        fireball[i] = { nextPos.first, nextPos.second, tmpMass, tmpSpeed, tmpDir };
    }
}

void sum_and_split() {
    vector<tuple<int, int, int, int, int>> tmpfireball; // 합친 결과를 담을 임시 리스트

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j].size() == 0) continue;
            if (board[i][j].size() == 1) {
                tmpfireball.push_back(board[i][j][0]);
                continue;
            }

            int sumMass = 0;
            int sumSpeed = 0;
            int count = board[i][j].size();
            int dirEvenCount = 0;
            int dirOddCount = 0;

            for (int k = 0; k < count; k++) {
                sumMass += get<2>(board[i][j][k]);
                sumSpeed += get<3>(board[i][j][k]);
                if (get<4>(board[i][j][k]) % 2 == 0) dirEvenCount++;
                else dirOddCount++;
            }

            int newMass = sumMass / 5;
            int newSpeed = sumSpeed / count;
            if (dirEvenCount == count || dirOddCount == count) {
                int newDir = 0;
                for (int a = 0; a < 4; a++) {
                    tmpfireball.push_back({ i, j, newMass, newSpeed, newDir });
                    newDir += 2;
                }
            }
            else {
                int newDir = 1;
                for (int a = 0; a < 4; a++) {
                    tmpfireball.push_back({ i, j, newMass, newSpeed, newDir });
                    newDir += 2;
                }
            }
        }
    }
    fireball = tmpfireball;
}

void solve() {
    for(int i=0; i<K; i++){
        move();
        sum_and_split();
    }

    int sumMass = 0;
    for (int i = 0; i < fireball.size(); i++) {
        sumMass += get<2>(fireball[i]);
    }

    cout << sumMass;
}

pair<int, int> getNextPos(int y, int x, int speed, int dir) {
    int offset = speed % N;
    int nextYplusD = y + offset;
    int nextXplusD = x + offset;
    int nextYminD = y - offset;
    int nextXminD = x - offset;

    if (nextYplusD > N) nextYplusD -= N;
    if (nextXplusD > N) nextXplusD -= N;
    if (nextYminD < 1) nextYminD += N;
    if (nextXminD < 1) nextXminD += N;

    switch (dir) {
    case 0:
        return { nextYminD, x };
    case 2:
        return { y, nextXplusD };
    case 4:
        return { nextYplusD , x };
    case 6:
        return { y, nextXminD };
    // 대각선 방향
    case 1:
        return { nextYminD, nextXplusD };
    case 3:
        return { nextYplusD, nextXplusD };
    case 5:
        return { nextYplusD, nextXminD };
    case 7:
        return { nextYminD, nextXminD };
    }
}

void epilogue() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j].clear();
        }
    }

    fireball.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tmpY, tmpX, mass, speed, dir;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> tmpY >> tmpX >> mass >> speed >> dir;
        board[tmpY][tmpX].push_back({ tmpY, tmpX, mass, speed, dir });
        fireball.push_back({ tmpY, tmpX, mass, speed, dir });
    }

    solve();
    epilogue();

    return 0;
}