// 문제 링크 https://www.acmicpc.net/problem/15649
#include <iostream>

using namespace std;
void backtrack(int);

int result[10];
bool isUsed[10];
int N, M;    // 1부터 N까지 수 중에서 M개를 고르는 수열

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	backtrack(0);

	return 0;
}

void backtrack(int num) { // num : 현재까지 채운 개수
	if (num == M) {    // M개 까지 모두 채웠을 경우
		for (int i = 0; i < M; i++) cout << result[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) { // 1부터 N까지 수 중에 고르기
		if (isUsed[i]) continue;

		result[num] = i;

		isUsed[i] = true;
		backtrack(num + 1);
		isUsed[i] = false;
	}
}
