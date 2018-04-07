#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3] = {};

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &dp[t][0], &dp[t][1], &dp[t][2]);
		dp[t][0] += min(dp[t - 1][1], dp[t - 1][2]);
		dp[t][1] += min(dp[t - 1][0], dp[t - 1][2]); 
		dp[t][2] += min(dp[t - 1][0], dp[t - 1][1]); 
	}
	printf("%d\n", min(min(dp[T][0], dp[T][1]), dp[T][2]));
	return 0;
}