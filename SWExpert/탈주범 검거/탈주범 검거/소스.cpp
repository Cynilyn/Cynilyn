#include <cstdio>
using namespace std;

int T, N, M, R, C, L;
int map[50][50][4];
int ans, type;
//DFS로 풀다보니 visit이 2개 필요했는데,
//캐치하지 못해서 헤맴,..
//특정 x, y에 도달하여 visit이 true가 되면서 ans++ 됬을 때
//다른 경로를 통해 x, y에 더 빠른 시간내로 도달함으로써
//기존에 가지 못했던 경로를 갈 수 있지만
//이전 과정에서 visit[x][y] = true로 지정해버렸기 때문에 그러한 경로들을 탐색하지 않음
//따라서 visitCount용과 일반 visit이 필요함.
//노말한 DFS는 아님. 왜 풀이가 BFS로 되어있는지 알겠음.
bool visitCount[50][50];
bool visit[50][50];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
//down, right, up, left
int open[8][4] = {
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 0, 1, 0, 1 },
	{ 0, 1, 1, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 1 },
	{ 0, 0, 1, 1 }
};

void sol(int x, int y, int t) {
	if (!visitCount[x][y]) {
		ans++;
		visitCount[x][y] = true;
	}
	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];
		int opp = (i + 2) % 4;
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)	continue;
		if (visit[nextX][nextY])	continue;

		if (map[x][y][i] && map[nextX][nextY][opp] && t + 1 <= L) {
			visit[x][y] = true;
			sol(nextX, nextY, t + 1);
			visit[x][y] = false;
		}
	}
	return;
}

int main() {
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		ans = 1;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &type);
				visitCount[j][k] = false;
				visit[j][k] = false;
				for (int d = 0; d < 4; d++) map[j][k][d] = open[type][d];
			}
		}

		visitCount[R][C] = true;
		visit[R][C] = true;
		sol(R, C, 1);

		printf("#%d %d\n", i, ans);
	}
	return 0;
}