// 문제 링크 https://www.acmicpc.net/problem/1182
#include <iostream>

using namespace std;
void backtrack(int, int);

int seq[21];
int num, sum, ans;       // 정수 개수, 합 S, 부분수열의 개수 1 ≤ N ≤ 20, |S| ≤ 1,000,000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> num >> sum;
	for(int i = 0; i < num; i++) cin >> seq[i];

	backtrack(0, 0);  // 0번 인덱스부터, sum이 0일때 부터 시작

	if (sum == 0) ans--;  // 합이 0인 경우 부분수열의 공집합인 경우 1개를 카운트에서 빼줘야함

	cout << ans;

	return 0;
}

void backtrack(int curPos, int curTotal) {
	if (curPos == num) {
		if(sum == curTotal) ans++;
		return;
	}

	/* 반드시 seq배열의 모든 요소가 들어가지 않아도 됨 */
	backtrack(curPos + 1, curTotal);              // 왼쪽 노드: 현재 값을 더하지 않은 경우
	backtrack(curPos + 1, curTotal + seq[curPos]);// 오른쪽 노드: 현재값을 더한 경우
	/* cf. 재귀가 2개이상 호출될 때에는 전역변수를 공유할수 없음 => 인자로 보내기 */
}
