#include <cstdio>
using namespace std;

int arr[7][2] = { 0 };
int N, k, x, y, answer = 0;

int main() {
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		arr[y][x]++;
	}

	for (int i = 1; i <= 6; i++) {
		if (arr[i][0] % k == 0)
			answer += arr[i][0] / k;
		else
			answer += arr[i][0] / k + 1;

		if (arr[i][1] % k == 0)
			answer += arr[i][1] / k;
		else
			answer += arr[i][1] / k + 1;
	}

	printf("%d\n", answer);

	return 0;
}