#include <cstdio>
using namespace std;

int N, K, s, grade, answer = 0;
int arr[3][2] = { 0 };

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s, &grade);
		arr[(grade-1) / 2][s]++;
	}

	if ((arr[0][0] + arr[0][1]) % K == 0)
		answer += (arr[0][0] + arr[0][1]) / K;
	else
		answer += (arr[0][0] + arr[0][1]) / K + 1;

	for (int i = 1; i < 3; i++) {
		if (arr[i][0] % K == 0)
			answer += arr[i][0] / K;
		else
			answer += arr[i][0] / K + 1;

		if (arr[i][1] % K == 0)
			answer += arr[i][1] / K;
		else
			answer += arr[i][1] / K + 1;
	}

	printf("%d\n", answer);

	return 0;
}