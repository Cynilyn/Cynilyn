//2012003385_±èÁøÇö_508
#include <cstdio>
using namespace std;

int N;
int rod[101];
int r[101];
int s[101];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &rod[i]);
	}
	rod[0] = 0;	r[0] = 0;	s[0] = 0;
	for (int j = 1; j <= N; j++) {
		int q = -1;
		for (int i = 1; i <= j; i++) {
			if (q < rod[i] + r[j - i]) {
				q = rod[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

	printf("%d\n", r[N]);	
	while (N > 0) {
		printf("%d ", s[N]);
		N = N - s[N];
	}

	return 0;
}
