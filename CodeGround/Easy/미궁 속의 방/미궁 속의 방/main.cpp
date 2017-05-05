#include <cstdio>
#include <iostream>
using namespace std;

int calculateNum(int x, int y, int N) {
	int startNum = 1, score;
	bool reverse = false;
	if (x + y - 1 > N) {
		x = N - x + 1;
		y = N - y + 1;
		reverse = true;
	}
	for (int i = 1; i < x + y - 1; i++)
		startNum += i;

	if ((x + y - 1) % 2 == 0)
		score = startNum + y - 1;
	else
		score = startNum + x - 1;

	if (reverse)
		return N*N - score + 1;
	else
		return score;
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC, N, K, test_case;
	char dir;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int score = 0, x = 1, y = 1;
		long long int totalScore = 1;
		scanf("%d %d\n", &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%c", &dir);
			switch (dir) {
			case 'D':
				y += 1;
				break;
			case 'U':
				y -= 1;
				break;
			case 'R':
				x += 1;
				break;
			case 'L':
				x -= 1;
				break;
			}
			score = calculateNum(x, y, N);
			totalScore += score;
		}		
		printf("Case #%d\n", test_case);
		printf("%lld\n", totalScore);
	}
	return 0;
}