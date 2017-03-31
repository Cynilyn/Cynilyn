#include <iostream>
using namespace std;

int main() {
	int n;
	long long int answer[81] = { 0 };
	long long int dp[81] = { 0 };
	cin >> n;
	dp[1] = 1;	dp[2] = 1;
	answer[1] = 4;	answer[2] = 6;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		answer[i] = answer[i - 1] + 2 * dp[i];
	}

	cout << answer[n] << endl;
	return 0;
}