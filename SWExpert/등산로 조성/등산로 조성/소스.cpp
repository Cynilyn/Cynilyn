#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, K, maxHeight, maxDist;
int map[8][8];
bool visit[8][8];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void searchMax(int x, int y, int dist, int height, bool dig) {

	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];
		int nextH = map[nextX][nextY];

		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) {
			continue;
		}
		if (visit[nextX][nextY]) {
			continue;
		}

		if (nextH < height) {
			visit[nextX][nextY] = true;
			searchMax(nextX, nextY, dist + 1, nextH, dig);
			visit[nextX][nextY] = false;
		}
		else {
			if (dig && nextH - K < height) {
				nextH = height - 1;
				dig = false;
				visit[nextX][nextY] = true;
				searchMax(nextX, nextY, dist + 1, nextH, dig);
				dig = true;
				visit[nextX][nextY] = false;
			}
		}
	}

	maxDist = max(maxDist, dist);
	return;
}

int main() {
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		maxHeight = 0, maxDist = 0;

		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &map[j][k]);
				visit[j][k] = false;
				maxHeight = max(maxHeight, map[j][k]);
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == maxHeight) {
					visit[j][k] = true;
					searchMax(j, k, 1, map[j][k], true);
					visit[j][k] = false;
				}
			}
		}
		printf("#%d %d\n", i, maxDist);		
	}	
	return 0;
}
