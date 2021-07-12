// 문제 링크 https://www.acmicpc.net/problem/6603
#include <iostream>
#include <algorithm>   // next_permutation
#include <string.h>    // memset

using namespace std;
void combinationExample();

int k;               // testcase 크기
int seq[13];         // 입력 받을 배열
int combination[13]; // 조합에 필요한 배열 0또는 1

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> k;   // testcase 크기
		if (k == 0) return 0;

		memset(combination, 0, 13);

		int num;
		for (int i = 0; i < k; i++) {
			cin >> num;
			seq[i] = num;
		}

		for (int i = k - 1; i >= 6; i--) {
			combination[i] = 1;
		}

		combinationExample();
		cout << '\n';
	}

	//https://www.acmicpc.net/problem/15649 next_permutation으로 풀어보기

	return 0;
}


void combinationExample() {
	do{
		for (int i = 0; i < k; i++)
			if (combination[i] == 0) cout << seq[i] << ' ';

		cout << '\n';
	} while (next_permutation(combination, combination + k));

	// 조합은 next_permutation과 배열에 0과 1을 이용하여 해결할 수 있음
	// ex) 5C3 : 5개에서 3개를 뽑을 때에는 배열을 { 0, 0, 0, 1, 1 } 로 둔다
}

// 백트래킹 풀이
/*
#include <iostream>
#include <string.h>    // memset

using namespace std;
void backtrack(int);

int k;               // testcase 크기
int seq[15];         // 입력 받을 배열
bool visited[15];    // 사용된 점인지 마킹
int result[15];      // 결과 저장

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> k;
		if (k == 0) return 0;

		memset(visited, false, 13);

		int num;
		for (int i = 0; i < k; i++) {
			cin >> num;
			seq[i] = num;
		}

		backtrack(0);
		cout << '\n';
	}

	//https://www.acmicpc.net/problem/15649 next_permutation으로 풀어보기

	return 0;
}

void backtrack(int size) {   // size : 현재까지 채운 개수

	if (size == 6) {  // size가 6이된 시점에는 result가 6개 저장된 상태
		for (int i = 0; i < 6; i++) cout << result[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visited[i]) continue;
		if (size >= 1 && result[size - 1] > seq[i]) continue; // 이전값 > 현재 넣을값 인 경우 오름차순 위배

		result[size] = seq[i];

		visited[i] = true;
		backtrack(size + 1);
		visited[i] = false;
	}
}
*/
