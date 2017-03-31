#include <cstdio>
using namespace std;

int abs(int a) {return a>0 ? a : -a;}
int arr[35];
bool dp[2][15310];

int main() {
	int N, M, a, x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0][arr[0]] = dp[0][0] = true;

	for (int i = 1; i < N; i++) {
		if (i % 2) {
			dp[1][arr[i]] = true;
			for (int j = 0; j < 15010; j++) {
				dp[1][j] |= dp[0][abs(j - arr[i])];
				dp[1][j] |= dp[0][j + arr[i]];
				dp[1][j] |= dp[0][j];
			}
		}
		else {
			dp[0][arr[i]] = true;
			for (int j = 0; j < 15010; j++) {
				dp[0][j] |= dp[1][abs(j - arr[i])];
				dp[0][j] |= dp[1][j + arr[i]];
				dp[0][j] |= dp[1][j];
			}
		}
	}

	scanf("%d", &M);
	if (N % 2) x = 0;
	else x = 1;
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		if (dp[x][a] == true && a <= 15000)
			printf("Y ");
		else
			printf("N ");
	}
	return 0;
}