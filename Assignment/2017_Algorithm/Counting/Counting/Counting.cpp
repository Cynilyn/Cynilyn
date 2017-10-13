//2012003385_±èÁøÇö_508
#include <cstdio>
#include <vector>
using namespace std;

int N, M, K;

int main() {
	int i;
	scanf("%d %d %d", &N, &M, &K);

	vector<int> arr(N + 1);
	vector<int> count(M + 1, 0);
	vector<int> A(K);
	vector<int> B(K);

	for (i = 0; i < K; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}

	for (i = 1; i < M; i++) {
		count[i] += count[i - 1];
	}

	for (i = 0; i < K; i++) {
		printf("%d\n", count[B[i]] - count[A[i] - 1]);
	}

	return 0;
}
