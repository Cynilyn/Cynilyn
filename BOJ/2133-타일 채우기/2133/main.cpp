#include <stdio.h>

int n;
int dp[20];

int main() {
	scanf("%d", &n);
	
	if (n % 2 == 1) {
		printf("0\n");
		return 0;
	}

	else if (n % 2 == 0)
		n = n / 2;
	dp[0] = 3;
	dp[1] = 11;
	for (int i = 2; i < n; i++) {
		dp[i] = 3 * dp[i - 1];
		for (int j = 2; j <= i; j++) {
			dp[i] += 2 * dp[i - j];
		}
		dp[i] += 2;
	}
	printf("%d\n", dp[n-1]);
	return 0;
}