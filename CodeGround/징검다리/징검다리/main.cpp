#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000009

long long Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K, L, obstacle_index;
		Answer = 0;
		cin >> N >> K >> L;

		vector<bool> have_obstacle(N + 1);
		vector<vector<long long> > dp;
		for (int i = 0; i <= N; i++) {
			vector<long long> temp(K + 2);
			dp.push_back(temp);
		}

		for (int i = 0; i < L; i++) {
			cin >> obstacle_index;
			have_obstacle[obstacle_index] = true;
		}

		dp[0][K + 1] = 1;
		for (int i = 1; i <= N; i++) {
			if (have_obstacle[i])
				continue;
			for (int j = 1; (j <= K) && (i - j >= 0); j++)
				dp[i][j] = (dp[i - j][K + 1] + MOD - dp[i - j][j]) % MOD;
			for (int j = 1; j <= K; j++)
				dp[i][K + 1] += dp[i][j];
		}
		Answer = dp[N][K + 1] % MOD;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}