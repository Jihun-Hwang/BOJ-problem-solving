// 문제 링크 https://www.acmicpc.net/problem/14470
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int initialTemp, targetTemp, frozenTime, zeroTime, heatTime;
	int result = 0;

	cin >> initialTemp >> targetTemp >> frozenTime >> zeroTime >> heatTime;

	if (initialTemp < 0) {
		result += abs(initialTemp) * frozenTime;
		result += targetTemp * heatTime;
		result += zeroTime;

		cout << result;

		return 0;
	}

	// initial is larger than 0
	result = (targetTemp - initialTemp) * heatTime;

	cout << result;

	return 0;
}