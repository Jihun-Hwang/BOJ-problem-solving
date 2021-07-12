// 문제 링크 https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <cmath>     // pow

using namespace std;
void setCycleInput(vector<char>*, string);
void setAdjState();
void rotate(int, int);

vector<char>* cycle[5];     // 톱니바퀴 4개를 담을 배열, index 0은 사용안함
vector<char> cycle1;        // 톱니바퀴 1
vector<char> cycle2;        // 톱니바퀴 2
vector<char> cycle3;        // 톱니바퀴 3
vector<char> cycle4;        // 톱니바퀴 4
bool isAdjStateSame[5][2];  // 인접한 톱니바퀴(index 2와 6)의 상태, 1차원 index : 톱니바퀴 번호, 2차원 index : 좌 우
int ans;
int targetCycleNum, direction;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string curLine;
	cin >> curLine; setCycleInput(&cycle1, curLine);
	cin >> curLine; setCycleInput(&cycle2, curLine);
	cin >> curLine; setCycleInput(&cycle3, curLine);
	cin >> curLine; setCycleInput(&cycle4, curLine);

	cycle[1] = &cycle1;
	cycle[2] = &cycle2;
	cycle[3] = &cycle3;
	cycle[4] = &cycle4;

	int rotationTime; cin >> rotationTime;
	while (rotationTime--) {
		cin >> targetCycleNum >> direction;

		setAdjState();
		rotate(targetCycleNum, direction);
	}

	for (int i = 1; i <= 4; i++)
		ans += (cycle[i]->at(0) - '0') * (int)pow(2, i - 1);

	cout << ans;

	return 0;
}

void rotate(int curCycleNum, int dir) {
	if (curCycleNum == 0 || curCycleNum == 5) return;

	// 시계방향(1)일 경우 index 7이 index 0으로, 반시계방향(-1)일 경우 index 0이 index 7로
	if (dir == 1) {
		cycle[curCycleNum]->insert(cycle[curCycleNum]->begin(), cycle[curCycleNum]->back());
		cycle[curCycleNum]->pop_back();
	}
	else {
		cycle[curCycleNum]->insert(cycle[curCycleNum]->end(), cycle[curCycleNum]->front());
		cycle[curCycleNum]->erase(cycle[curCycleNum]->begin(), cycle[curCycleNum]->begin() + 1);
	}

	if (!isAdjStateSame[curCycleNum][0]) {
		isAdjStateSame[curCycleNum][0] = isAdjStateSame[curCycleNum - 1][1] = true; // 역으로 다시 돌아가지 못하게 하기 위함
		rotate(curCycleNum - 1, dir * -1);
	}
	if (!isAdjStateSame[curCycleNum][1]) {
		isAdjStateSame[curCycleNum][1] = isAdjStateSame[curCycleNum + 1][0] = true;
		rotate(curCycleNum + 1, dir * -1);
	}
}

void setCycleInput(vector<char>* curCycle, string line) {
	for (int i = 0; i < 8; i++)
		curCycle->push_back(line[i]);
}

void setAdjState() {
	if (cycle1[2] == cycle2[6]) isAdjStateSame[1][1] = isAdjStateSame[2][0] = true;
	else isAdjStateSame[1][1] = isAdjStateSame[2][0] = false;

	if (cycle2[2] == cycle3[6]) isAdjStateSame[2][1] = isAdjStateSame[3][0] = true;
	else isAdjStateSame[2][1] = isAdjStateSame[3][0] = false;

	if (cycle3[2] == cycle4[6]) isAdjStateSame[3][1] = isAdjStateSame[4][0] = true;
	else isAdjStateSame[3][1] = isAdjStateSame[4][0] = false;
}