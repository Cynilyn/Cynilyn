#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int r_x;
	int r_y;
	int b_x;
	int b_y;
}coor;
int N, M; // N : 세로 사이즈, M : 가로 사이즈
int o_x, o_y, answer = 11; // 탈출구 O의 x,y 좌표
char buffer;
char maze[11][11];
coor init;
coor end_signal = { 0, 0, 0, 0 };

// 구슬은 같은 위치에 존재할 수 없다, 따라서 다음 목적지가 같은지 체크하고
// 같으면 다음 위치를 조정해줘야 된다.
bool same_next_position(coor next_point) {
	if (next_point.b_x == next_point.r_x && next_point.b_y == next_point.r_y) {
		return true;
	}
	return false;
}

bool find_exit(int x, int y, int index) {
	if (x == o_x && y == o_y) {
		if (index) {
			end_signal.r_x = -1;
			return true;
		}	
		else {
			end_signal.b_x = -1;
			return true;
		}			
	}		
	return false;
}

coor find_next_point(int r_x, int r_y, int b_x, int b_y, int direction) {
	coor origin = { r_x, r_y, b_x, b_y };
	coor next_point;
	switch (direction) {
	case 1: // 동쪽으로 이동하는 경우
		while (maze[b_x][b_y + 1] != '#') {
			b_y += 1;
			if (find_exit(b_x, b_y, 0))
				return end_signal;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		while (maze[r_x][r_y + 1] != '#') {
			r_y += 1;
			if(find_exit(r_x, r_y, 1))
				return end_signal;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		//다음 목적지가 같으면 다음 목적지를 조정.
		if (same_next_position(next_point)) {
			if (origin.b_y > origin.r_y)
				next_point.r_y -= 1;
			else
				next_point.b_y -= 1;
		}
		break;

	case 2: // 서쪽으로 이동하는 경우
		while (maze[b_x][b_y - 1] != '#') {
			b_y -= 1;
			if (find_exit(b_x, b_y, 0))
				return end_signal;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		while (maze[r_x][r_y - 1] != '#') {
			r_y -= 1;
			if (find_exit(r_x, r_y, 1))
				return end_signal;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		if (same_next_position(next_point)) {
			if (origin.b_y > origin.r_y)
				next_point.b_y += 1;
			else
				next_point.r_y += 1;
		}
		break;

	case 3: // 남쪽으로 이동하는 경우
		while (maze[b_x + 1][b_y] != '#') {
			b_x += 1;
			if (find_exit(b_x, b_y, 0))
				return end_signal;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		while (maze[r_x + 1][r_y] != '#') {
			r_x += 1;
			if (find_exit(r_x, r_y, 1))
				return end_signal;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		if (same_next_position(next_point)) {
			if (origin.b_x > origin.r_x)
				next_point.r_x -= 1;
			else
				next_point.b_x -= 1;
		}
		break;

	case 4: // 북쪽으로 이동하는 경우
		while (maze[b_x - 1][b_y] != '#') {
			b_x -= 1;
			if (find_exit(b_x, b_y, 0))
				return end_signal;
		}
		next_point.b_x = b_x; next_point.b_y = b_y;

		while (maze[r_x - 1][r_y] != '#') {
			r_x -= 1;
			if (find_exit(r_x, r_y, 1))
				return end_signal;
		}
		next_point.r_x = r_x; next_point.r_y = r_y;

		if (same_next_position(next_point)) {
			if (origin.b_x > origin.r_x)
				next_point.b_x += 1;
			else
				next_point.r_x += 1;
		}
		break;
	}

	return next_point;
}

void find_path(int r_x, int r_y, int b_x, int b_y, int depth) {
	coor next;
	int dir = 1;

	if (depth > 10)
		return;

	while (dir < 5) { // 동,서,남,북 순으로 길을 파악
		next = find_next_point(r_x, r_y, b_x, b_y, dir);
		if (end_signal.b_x != -1) {
			if (end_signal.r_x == -1) {
				answer = min(answer, depth);
				end_signal.r_x++;
				return;
			}
			find_path(next.r_x, next.r_y, next.b_x, next.b_y, depth + 1);
		}
		else
			end_signal.b_x = 0;
		dir++;
	}
}

int main() {
	scanf("%d %d\n", &N, &M);

	//미로 정보 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == 'O') {
				o_x = i; o_y = j;
			}
			else if (maze[i][j] == 'R') {
				init.r_x = i;	
				init.r_y = j;
			}
			else if (maze[i][j] == 'B') {
				init.b_x = i;
				init.b_y = j;
			}
		}
		//버퍼에 남아있는 개행 문자 '\n' 제거용
		scanf("%c", &buffer);
	}

	find_path(init.r_x, init.r_y, init.b_x, init.b_y, 1);
	
	if (answer > 10)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}