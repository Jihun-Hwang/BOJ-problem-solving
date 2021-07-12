// 문제 링크 https://www.acmicpc.net/problem/1759
#include <iostream>
#include <algorithm>

using namespace std;
void backtrack(int, int, int, int, string);
bool isVowel(char);

char input[15];   // 3 ~ 15
int resultLen, inputLen;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> resultLen >> inputLen;
	for (int i = 0; i < inputLen; i++) cin >> input[i];
	sort(input, input + inputLen);   // 오름차순 정렬

	backtrack(0, 0, 0, 0, ""); // 입력의 index, 현재 선택된 개수, 모음개수, 자음개수, 현재까지 결과

	return 0;
}

void backtrack(int curIdx, int curLen, int numMo, int numJa, string curPassword) {
	if (curLen == resultLen) {
		// 위 if문과 같이 쓸수 없음.
		// numMo >= 1 && numJa >= 2가 아니더라도 resultLen에 도달하면 재귀 탈출조건이 만족되기 때문
		if(numMo >= 1 && numJa >= 2)
			cout << curPassword + '\n';
		return;
	}
	if (curIdx == inputLen) return;

	/* 상태공간트리의 자식노드는 3개, 반드시 input배열의 모든 요소가 들어가지 않아도 됨 */

	// 왼쪽 노드: 모음을 더해보는 case
	if (isVowel(input[curIdx]))
		backtrack(curIdx + 1, curLen + 1, numMo + 1, numJa, curPassword + input[curIdx]);

	// 가운데 노드: 자음을 더하는 case
	else
		backtrack(curIdx + 1, curLen + 1, numMo, numJa + 1, curPassword + input[curIdx]);

	// 오른쪽 노드: 현재 문자를 skip(결과에 더하지 않음)
	backtrack(curIdx + 1, curLen, numMo, numJa, curPassword);
}

bool isVowel(char val) {
	return val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u';
}
