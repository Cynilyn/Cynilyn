#include <cstdio>
using namespace std;

int T, N, M, R, C, L;
int map[50][50][4];
int ans, type;
//DFS�� Ǯ�ٺ��� visit�� 2�� �ʿ��ߴµ�,
//ĳġ���� ���ؼ� ���,..
//Ư�� x, y�� �����Ͽ� visit�� true�� �Ǹ鼭 ans++ ���� ��
//�ٸ� ��θ� ���� x, y�� �� ���� �ð����� ���������ν�
//������ ���� ���ߴ� ��θ� �� �� ������
//���� �������� visit[x][y] = true�� �����ع��ȱ� ������ �׷��� ��ε��� Ž������ ����
//���� visitCount��� �Ϲ� visit�� �ʿ���.
//�븻�� DFS�� �ƴ�. �� Ǯ�̰� BFS�� �Ǿ��ִ��� �˰���.
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