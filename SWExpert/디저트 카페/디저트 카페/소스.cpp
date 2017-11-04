#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
int item[20][20];
int ans, range;
int dir[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

void sol(int x, int y) {
	for (int a = 1; a < N; a++) {
		for (int b = 1; b < N; b++) {
			if ((y + a < N) && (x + a + b < N) && (y - b >= 0) && (2 * (a + b) > ans)) {
				vector<bool> visit(101, false);
				bool check = true;
				int curX = x, curY = y;
				for (int d = 0; d < 4; d++) {
					if (d % 2 == 0) {
						range = a;
					}
					else {
						range = b;
					}
					for (int i = 0; i < range; i++) {
						curX += dir[d][0];
						curY += dir[d][1];
						if (!visit[item[curX][curY]]) {
							visit[item[curX][curY]] = true;
						}
						else {
							check = false;
							break;
						}
					}
					if (!check) {
						break;
					}
				}
				if (check) {
					ans = 2 * (a + b);
				}				
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		ans = -1;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &item[j][k]);
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				sol(j, k);
			}
		}
		printf("#%d %d\n", i, ans);
	}
	return 0;
}