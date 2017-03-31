#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, M, s, e;
	scanf("%d", &N);
	vector<int> number(N + 1);
	vector<vector<int> >dp;
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		tmp.resize(N + 1);
		dp.push_back(tmp);
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", &number[i]);

	for (int i = 1; i <= N; i++)
		dp[i][i] = 1;
	for (int i = 2; i <= N; i++) {
		if (number[i - 1] == number[i])
			dp[i - 1][i] = 1;
	}

	for (int i = 3; i <= N; i++) {
		for (int j = i - 2; j > 0; j--) {
			if (number[j] == number[i]) {
				dp[j][i] = dp[j + 1][i - 1];
			}
			else
				dp[j][i] = 0;
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e]);
	}
	return 0;
}