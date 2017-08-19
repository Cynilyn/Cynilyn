#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		Answer = 0;
		cin >> N;
		vector<int> P(N + 1, 0);
		vector<int> Q(N + 1, 0);
		vector<int> dp(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> Q[i];
		}

		dp[1] = max(P[1], Q[1]);
		dp[2] = max(Q[2], P[1] + P[2]);
		dp[2] = max(dp[2], Q[1] + P[2]);

		for (int i = 3; i <= N; i++) {
				dp[i] = max(dp[i - 1] + P[i], dp[i - 2] + Q[i]);
		}

		Answer = dp[N];
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}