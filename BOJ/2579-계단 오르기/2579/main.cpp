#include <iostream>
#include <stdio.h>
#define compare(a, b) {(a > b)? a : b}

using namespace std;

int main() {
	int N = 0;
	int dp[301] = { 0 };
	int stair[301] = { 0 };

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= N; i++)
		dp[i] = compare(dp[i - 2] + stair[i], dp[i - 3] + stair[i-1] + stair[i]);
	
	printf("%d\n", dp[N]);
	
	return 0;
}