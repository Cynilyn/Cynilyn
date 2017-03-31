#include <cstdio>
using namespace std;
#define MAX(a,b) a > b? a : b

int matrix[1000][1000];
int dp[1000][1000];
int line[2][1000];

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			scanf("%d", &matrix[i][j]);
	}

	dp[0][0] = matrix[0][0];
	for (i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + matrix[0][i];

	for (i = 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			line[0][j] = line[1][j] = dp[i - 1][j] + matrix[i][j];
		}
		for (j = 1; j < m; j++) {
			line[0][j] = MAX(line[0][j - 1] + matrix[i][j], line[0][j]);
		}
		for (j = m-2; j >= 0; j--) {
			line[1][j] = MAX(line[1][j + 1] + matrix[i][j], line[1][j]);
		}
		for (j = 0; j < m; j++) {
			dp[i][j] = MAX(line[0][j], line[1][j]);
		}
	}
	printf("%d\n", dp[n - 1][m - 1]);
	return 0;
}