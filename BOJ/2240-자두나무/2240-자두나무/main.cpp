#include <cstdio>
#include <vector>
using namespace std;
#define MAX(a,b) a > b ? a : b

int main() {
	int T, W, num;
	scanf("%d %d", &T, &W);
	vector<vector<int> >dp;
	vector<int> order(T);
	for (int i = 0; i <= W+1; i++) {
		vector<int> temp;
		temp.resize(T+1);
		dp.push_back(temp);
	}
	for (int i = 1; i <= T; i++) {
		scanf("%d", &num);
		if (num-1) {
			for (int j = 1; j <= W; j += 2) {
				dp[j + 1][i] = MAX(dp[j][i - 1]+1, dp[j + 1][i - 1]+1);
			}
			for (int j = 0; j <= W; j += 2)
				dp[j + 1][i] = dp[j + 1][i - 1];
		}
		else {
			for (int j = 0; j <= W; j += 2) {
				dp[j + 1][i] = MAX(dp[j][i - 1]+1, dp[j + 1][i - 1]+1);
			}
			for (int j = 1; j <= W; j += 2)
				dp[j + 1][i] = dp[j + 1][i - 1];
		}
	}

	printf("%d", MAX(dp[W + 1][T], dp[W][T]));
	return 0;
}