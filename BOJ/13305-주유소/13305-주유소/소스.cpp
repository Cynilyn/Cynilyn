#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, temp, lowest_price_index = 1;
	scanf("%d", &N);
	vector<long long int> dp(N + 1);
	vector<long long int> oil_cost(N + 1);
	vector<long long int> move_cost(N + 1);

	for (int i = 2; i <= N; i++) {
		scanf("%lld", &move_cost[i]);
		move_cost[i] += move_cost[i - 1];
	}
		
	for (int i = 1; i <= N; i++)
		scanf("%lld", &oil_cost[i]);

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[lowest_price_index] + oil_cost[lowest_price_index] * (move_cost[i] - move_cost[lowest_price_index]);
		if (oil_cost[i] < oil_cost[lowest_price_index])
			lowest_price_index = i;
	}

	printf("%lld\n", dp[N]);

	return 0;
}