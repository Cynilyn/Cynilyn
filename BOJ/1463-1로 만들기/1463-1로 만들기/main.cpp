#include <cstdio>
#include <vector>
using namespace std;
#define MIN(a,b) a < b? a : b

int main() {
	int N, i;
	vector<int> dp;
	scanf("%d", &N);
	dp.resize(N + 1);
	dp[1] = 0;	dp[2] = 1;	dp[3] = 1;
	for (i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = MIN(dp[i], dp[i / 3]+1);
		if (i % 2 == 0)
			dp[i] = MIN(dp[i], dp[i / 2]+1);
	}
	printf("%d", dp[N]);
	return 0;
}