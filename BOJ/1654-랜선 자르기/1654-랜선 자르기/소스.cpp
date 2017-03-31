#include <cstdio>
using namespace std;

long long int K, N, answer, low = 0, mid, high = 0, line_num;
int line[10010];

int main() {
	//가지고 있는 갯수 K, 필요한 갯수 N;
	scanf("%lld %lld", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &line[i]);
		if (high < line[i])
			high = line[i];
	}

	while (low <= high) {
		line_num = 0;
		mid = (high + low) / 2;
		for (int i = 0; i < K; i++)
			line_num += line[i] / mid;
		if (line_num < N)
			high = mid - 1;
		else {
			if (answer < mid)
				answer = mid;
			low = mid + 1;
		}			
	}

	printf("%d\n", answer);

	return 0;
}