/*
10
1 2 0 1 3 2 1 5 4 2
*/
#include <cstdio>
#include <vector>
#define MAX 987654321
using namespace std;

int main() {
	int n, num, i = 0;
	scanf("%d", &n);
	vector<int> dp(n + 101, MAX);
	vector<int> jump(n + 101, 0);

	for (int i = 0; i < n; i++)
		scanf("%d", &jump[i]);
	dp[0] = 0;

	if (n == 1) {
		printf("0\n");
		return 0;
	}	

	while (i + jump[i] + 1 < n) {
		if (dp[i] != MAX) {
			for (int j = 0; j < jump[i]; j++) {
				if (dp[i] < dp[i + j + 1]) {
					dp[i + j + 1] = dp[i] + 1;
				}
			}
		}
		i++;
	}
	
	printf("%d\n", dp[i] != MAX ? dp[i] + 1 : -1);
	return 0;
}