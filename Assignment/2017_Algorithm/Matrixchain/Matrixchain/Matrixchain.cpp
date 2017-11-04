//2012003385_±èÁøÇö_508
#include <cstdio>
#include <algorithm>
using namespace std;

int N, ans;
int dp[101][101], s[101][101], p[102];

void recur(int i, int j) {
	if (i == j) {
		printf("%d", i);
		return;
	}
	else {
		printf("(");
		recur(i, s[i][j]);
		recur(s[i][j] + 1, j);
		printf(")");
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i <= N; i++) {
		scanf("%d", &p[i]);
	}

	for (int l = 1; l < N; l++) {
		for (int i = 1; i < N; i++) {
			int j = i + l;
			dp[i][j] = 987654321;
			for (int k = i; k < j; k++) {
				int calc = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (dp[i][j] > calc) {
					dp[i][j] = calc;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", dp[1][N]);
	recur(1, N);
	printf("\n");
	
	return 0;
}