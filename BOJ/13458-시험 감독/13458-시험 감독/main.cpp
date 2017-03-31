#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, B, C;
	long long int answer = 0;
	scanf("%d", &N);
	vector<int> A(N + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			if (A[i] % C == 0)
				answer += A[i] / C;
			else
			{
				answer += A[i] / C + 1;
			}
		}
		answer++;
	}

	printf("%lld\n", answer);
	return 0;
}