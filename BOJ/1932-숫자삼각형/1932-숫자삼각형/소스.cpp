#include <cstdio>
#include <algorithm>
using namespace std;

int arr[501][501] = { 0 };

int main() {
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		ans = max(arr[N][i], ans);
	}
	printf("%d\n", ans);
	return 0;
}