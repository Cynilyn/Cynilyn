#include <cstdio>
using namespace std;

typedef struct {
	int r_x;
	int r_y;
	int b_x;
	int b_y;
}coor;
int N, M; // N : ���� ������, M : ���� ������
char buffer;
char maze[11][11];
bool visit[11][11];
coor init;

coor find_next_point(int r_x, int r_y, int b_x, int b_y, int direction) {
	coor next_point;
	switch (direction) {
	case 1:
		while (maze[r_x][r_y + 1] != '#') {
			r_y += 1;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		while (maze[b_x][b_y + 1] != '#') {
			b_y += 1;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		//���� �������� ������ ���� �������� ����.
		if (same_next_position) {
			if (next_point.b_y > next_point.r_y)
				next_point.r_y -= 1;
			else
				next_point.b_y -= 1;
		}
		break;

	case 2:
		while (maze[r_x][r_y - 1] != '#') {
			r_y -= 1;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		while (maze[b_x][b_y - 1] != '#') {
			b_y -= 1;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		if (same_next_position) {
			if (next_point.b_y > next_point.r_y)
				next_point.b_y += 1;
			else
				next_point.r_y += 1;
		}
		break;

	case 3:
		while (maze[r_x + 1][r_y] != '#') {
			r_x += 1;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		while (maze[b_x + 1][b_y] != '#') {
			b_x += 1;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		if (same_next_position) {
			if (next_point.b_x > next_point.r_x)
				next_point.r_x -= 1;
			else
				next_point.b_x -= 1;
		}
		break;

	case 4:
		while (maze[r_x - 1][r_y] != '#') {
			r_x -= 1;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		while (maze[b_x - 1][b_y] != '#') {
			b_x -= 1;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		if (same_next_position) {
			if (next_point.b_x > next_point.r_x)
				next_point.b_x += 1;
			else
				next_point.r_x += 1;
		}
		break;
	}

	return next_point;
}

// ������ ���� ��ġ�� ������ �� ����, ���� ���� �������� ������ üũ�ϰ�
// ������ ���� ��ġ�� ��������� �ȴ�.
bool same_next_position(coor next_point) {
	if (next_point.b_x == next_point.r_x && next_point.b_y == next_point.r_y) {
		return true;
	}
	return false;
}

void find_path(int r_x, int r_y, int b_x, int b_y) {
	coor next;
	int dir = 1;
	visit[r_x][r_y] = 1;
	while (dir < 5) { // ��, ��, ��, �� ������ ���� �ľ�
		next = find_next_point(r_x, r_y, b_x, b_y, dir);

		// �ĺ��� ������ ���� �������� ���� �湮 �� �� ���¸�
		if (visit[next.r_x][next.r_y] == 0) { 
			find_path(next.r_x, next.r_y, next.b_x, next.b_y);
		}
		dir++;
	}
}

int main() {
	scanf("%d %d\n", &N, &M);

	//�̷� ���� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == '.' || maze[i][j] == 'O')
				visit[i][j] = 0;
			else
				visit[i][j] = 1;
		}
		//���ۿ� �����ִ� ���� ���� '\n' ���ſ�
		scanf("%c", &buffer);
	}

	return 0;
}