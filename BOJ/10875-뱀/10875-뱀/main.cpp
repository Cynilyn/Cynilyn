#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

enum class Direction {
	left, right, up, down
};

typedef struct coor {
	int x;
	int y;
};

int L, N, Length;
long long int LastCount, Count = 0;
int LastX = 0, LastY = 0;
char Dir;
bool Death = false;
Direction LastDir;
Direction NowDir = Direction::right;
vector<coor> Snake;

int main() {
	scanf("%d %d", &L, &N);
	Snake.push_back({ 0, 0 });
	for (int i = 1; i <= N + 1; i++) {
		if (i != N + 1)
			scanf("%d %c", &Length, &Dir);
		else
			Length = 2 * L + 2;
		
		LastCount = Count;
		LastDir = NowDir;

		switch (LastDir) {
		case Direction::right:
			LastX += Length;
			Count += Length;
			if (Dir == 'L')
				NowDir = Direction::up;
			else
				NowDir = Direction::down;
			break;

		case Direction::left:
			LastX -= Length;
			Count += Length;
			if (Dir == 'L')
				NowDir = Direction::down;
			else
				NowDir = Direction::up;
			break;

		case Direction::up:
			LastY += Length;
			Count += Length;
			if (Dir == 'L')
				NowDir = Direction::left;
			else
				NowDir = Direction::right;
			break;

		case Direction::down:
			LastY -= Length;
			Count += Length;
			if (Dir == 'L')
				NowDir = Direction::right;
			else
				NowDir = Direction::left;
			break;
		}
	
		Snake.push_back({ LastX,LastY });			
		int meet_first = 0;

		if (i % 2 == 1) { //x축 방향 따라서 움직일 때
			for (int j = 1; j <= i - 2; j++) {
				if (j % 2 == 1) { // 평행하게 만날 때
					if (Snake[i].y == Snake[j].y) {
						switch (LastDir) {
						case Direction::right: // 이러면 snake[i]가 더 오른쪽에 있음.
							if (((Snake[i].x >= Snake[j].x) || (Snake[i].x >= Snake[j - 1].x)) &&
								((Snake[i - 1].x <= Snake[j].x) || (Snake[i - 1].x <= Snake[j - 1].x))) { // 교차하는 경우
								meet_first = max(meet_first, max(Snake[i].x - Snake[j].x, Snake[i].x - Snake[j - 1].x));
								Death = true;
							}
							break;
						case Direction::left: // 이러면 snake[i]가 더 왼쪽에 있음.
							if (((Snake[i].x <= Snake[j].x) || (Snake[i].x <= Snake[j - 1].x)) && 
								((Snake[i - 1].x >= Snake[j].x) || (Snake[i- 1].x >= Snake[j - 1].x))) {
								meet_first = max(meet_first, abs(min(Snake[i].x - Snake[j].x, Snake[i].x - Snake[j - 1].x)));
								Death = true;
							}
							break;
						}
					}
				}
				else { // 교차하며 만날 때
					if ((Snake[j].y >= Snake[i].y) == (Snake[j - 1].y <= Snake[i].y)) {
						if ((Snake[i].x >= Snake[j].x) == (Snake[i - 1].x <= Snake[j].x)) {
							Death = true;
							meet_first = max(meet_first, abs(Snake[i].x - Snake[j].x));
						}
					}
				}
			}
			if (Snake[i].x > L) {
				meet_first = max(meet_first, abs(L + 1 - LastX));
				Death = true;
			}
			else if (Snake[i].x < -L) {
				meet_first = max(meet_first, abs(-L - 1 - LastX));
				Death = true;
			}
		}

		else { // y축 방향 따라서 움직일 때
			for (int j = 1; j <= i - 2; j++) {
				if (j % 2 == 0) { // 평행하게 만날 때
					if (Snake[i].x == Snake[j].x) {
						switch (LastDir) {
						case Direction::up: // 
							if (((Snake[i].y >= Snake[j].y) || (Snake[i].y >= Snake[j - 1].y)) &&
								((Snake[i - 1].y <= Snake[j].y) || (Snake[i - 1].y <= Snake[j- 1].y))){
								meet_first = max(meet_first, max(Snake[i].y - Snake[j].y, Snake[i].y - Snake[j - 1].y));
								Death = true;
							}
							break;
						case Direction::down:
							if (((Snake[i].y <= Snake[j].y)|| (Snake[i].y <= Snake[j - 1].y)) &&
								((Snake[i - 1].y >= Snake[j].y) || (Snake[i - 1].y >= Snake[j - 1].y))){
								meet_first = max(meet_first, abs(min(Snake[i].y - Snake[j].y, Snake[i].y - Snake[j - 1].y)));
								Death = true;
							}
							break;
						}
					}
				}
				else { // 교차하며 만날 때
					if ((Snake[j].x >= Snake[i].x) == (Snake[j - 1].x <= Snake[i].x)) {
						if ((Snake[i].y >= Snake[j].y) == (Snake[i - 1].y <= Snake[j - 1].y)) {
							Death = true;
							meet_first = max(meet_first, abs(Snake[i].y - Snake[j].y));
						}
					}
				}
			}
			if (Snake[i].y > L) {
				meet_first = max(meet_first, abs(L + 1 - LastY));
				Death = true;
			}
			else if (Snake[i].y < -L) {
				meet_first = max(meet_first, abs(-L - 1 - LastY));
				Death = true;
			}
		}
		if (Death == true) {
			Count -= meet_first;
			break;
		}			
	}
	printf("%lld\n", Count);
	return 0;
}