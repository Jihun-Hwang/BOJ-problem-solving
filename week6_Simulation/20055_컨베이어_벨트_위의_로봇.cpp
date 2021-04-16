// 문제 링크 https://www.acmicpc.net/problem/20055
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, bool>> L;   // { 내구도, 로봇여부 }
int N, K;

void epilogue(){
    L.clear();
}

void intitial() {
    cin >> N >> K;
    int inputLen = 2 * N;
    int tempVal;

    for (int i = 0; i < inputLen; i++) {
        cin >> tempVal;
        L.push_back({ tempVal, false });
    }
    //L[0].second = true;   // 올라가는 위치에 로봇을 올림
}

void solve() {
    int step = 0;
    int zeroCount = 0;

    while (true) {
        step++;

        // 1. 벨트가 한 칸 회전한다.
        auto tempPair = L.end() - 1;
        L.insert(L.begin(), { (*tempPair).first, (*tempPair).second });
        L.erase(L.end() - 1);  // 회전
        L[N].second = false;   // 내려가는 위치 다음 칸에 로봇이 위치할 수 없음


        // 2. 가장 먼저 벨트에 올라간 로봇부터 이동가능한 로봇은 이동
        if (L[N - 1].second == true) L[N - 1].second = false; // 내려가는 위치의 로봇을 내림

        for (int i = N - 1; i >= 0; i--) {
            if (L[i].second == false) continue; // 현재위치에 로봇자체가 없음 : 이동불가
            if (L[i + 1].second == true) continue; // 현재위치 앞에 로봇이 있음 : 이동불가
            if (L[i + 1].first <= 0) continue;  // 현재위치 앞에 내구성이 0임 : 이동불가

            L[i + 1].second = true; // 로봇이동
            L[i + 1].first -= 1;  // 내구성 감소
            L[i].second = false;

            if (L[i + 1].first == 0) zeroCount++;
            if (zeroCount == K) {
                cout << step;
                return;
            }

            L[N].second = false; // 내려가는 위치 다음 칸에 로봇이 위치할 수 없음
        }

        // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
        if (L[0].second == false && L[0].first > 0) {
            L[0].first -= 1;
            L[0].second = true;

            if (L[0].first == 0) zeroCount++;
            if (zeroCount == K) {
                cout << step;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    intitial();
    solve();
    epilogue();

    return 0;
}