//2012003385_±èÁøÇö_508
#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;

int dp[501][501];
int path[501][501];
char a[501], b[501];
stack<char> ans;
int la, lb, i, j;

int main() {
	scanf("%s", a);
	scanf("%s", b);
	if (strcmp(a, b) == 1) {
		swap(a, b);
	}

	la = strlen(a);
	lb = strlen(b);

	for (i = 0; i <= la; i++) {
		dp[0][i] = 0;
		path[0][i] = 0;
	}
	for (i = 0; i <= lb; i++) {
		dp[i][0] = 0;
		path[i][0] = 0;
	}

	for (i = 1; i <= lb; i++) {
		for (j = 1; j <= la; j++) {
			if (a[j - 1] == b[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				path[i][j] = 1;
			}
			else {
				if (dp[i - 1][j] >= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					path[i][j] = 2;
				}
				else if(dp[i -1][j] < dp[i][j - 1]){
					dp[i][j] = dp[i][j - 1];
					path[i][j] = 3;
				}
			}
		}
	}

	while (la != 0 && lb != 0) {
		if (path[lb][la] == 1) {
			ans.push(b[lb - 1]);
			la -= 1;
			lb -= 1;
		}
		else if (path[lb][la] == 2) {
			lb -= 1;
		}
		else if (path[lb][la] == 3){
			la -= 1;
		}
	}

	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}