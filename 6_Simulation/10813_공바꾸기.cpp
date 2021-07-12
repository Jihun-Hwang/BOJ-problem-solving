// 문제 링크 https://www.acmicpc.net/problem/10813
#include <iostream>

using namespace std;

int basketList[101];                 // index 0 is not used
int basketSize, changeCount;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> basketSize >> changeCount;

	for (int i = 1; i <= basketSize; i++) {
		basketList[i] = i;
	}

	while (changeCount--) {
		int basket1, basket2;
		cin >> basket1 >> basket2;

		int tmp = basketList[basket2];
		basketList[basket2] = basketList[basket1];
		basketList[basket1] = tmp;
	}

	for (int i = 1; i <= basketSize; i++) {
		cout << basketList[i] << ' ';
	}

	return 0;
}