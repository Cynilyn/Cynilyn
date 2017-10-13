//2012003385_±èÁøÇö_508
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int N, M, i, num, Answer = 0;
	scanf("%d %d", &N, &M);
	map<int, bool> visit;

	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		visit[num] = true;
	}

	for (i = 0; i < M; i++) {
		scanf("%d", &num);
		if (visit[num]) {
			Answer++;
		}
	}
	printf("%d\n", Answer);
	return 0;
}