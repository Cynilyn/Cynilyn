#include <cstdio>
#include <vector>
using namespace std;
#define MIN(a,b) a < b ? a : b

int main() {
	int N, tmp = 0, count = 0;
	int capt[121];
	scanf("%d", &N);
	vector<int> dp(N+1);
	capt[0] = 0;
	for (int i = 1; i <= N; i++)
		dp[i] = i;
	for (int i = 1; i <= 120; i++) {
		capt[i] = capt[i - 1];
		for (int j = 1; j <= i; j++)
			capt[i] += j;
		if (capt[i] <= N)
			dp[capt[i]] = 1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= 120; j++) {
			if (i > capt[j]) {
				dp[i] = MIN(dp[i], dp[i - capt[j]]+1);
			}
			else
				break;
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}