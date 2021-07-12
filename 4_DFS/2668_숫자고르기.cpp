// 문제 링크 https://www.acmicpc.net/problem/2668
#include <iostream>
#include <string.h>

using namespace std;
void dfs(int);

int number[101];     // 인덱스 1부터 사용
bool visited[101];   // cycle생성 여부를 판단하기 위함 ***
int result[101];     // 인덱스 오름차순으로 dfs를 실행하기 때문에 자동으로 정렬되어 저장됨
int num, startPos, resultIdx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> num;
	for (int i = 1; i <= num; i++) cin >> number[i];

	for (int i = 1; i <= num; i++) {
		memset(visited, false, sizeof(visited));
		startPos = i;   // 시작점 세팅
		dfs(i);
	}

	cout << resultIdx << '\n';
	for(int i=0; i<resultIdx; i++) cout << result[i] << '\n';

	return 0;
}

void dfs(int curPos) {
	if (visited[curPos]) {   // 조건문 주의 : 아래 if문과 같이 쓸수 없음. cycle이 생성되었는지 판단하기 위함
		if (curPos == startPos) result[resultIdx++] = startPos;
	}
	else {  // else로 반드시 묶어 줘야 위 if에 걸렸을때 else부분을 실행하지 않고 탈출할 수 있음.
		visited[curPos] = 1;
		dfs(number[curPos]);
	}
}
