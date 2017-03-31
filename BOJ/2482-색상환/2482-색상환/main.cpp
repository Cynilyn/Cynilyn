#include <cstdio>
#include <jansson.h>
using namespace std;
#define MOD 1000000003

int dp[1001][501];

int main() 
	int N, K;
	scanf("%d %d", &N, &K);
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	if (2 * K > N) {
		printf("0\n");
		return 0;
	}		
	else {
		for (int i = 2; i < N; i++) {
			for (int j = 0; j <= i / 2 + 1; j++) {
				if (j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1])% MOD;
			}
		}
	}
	printf("%d\n", (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD);
	return 0;	
}