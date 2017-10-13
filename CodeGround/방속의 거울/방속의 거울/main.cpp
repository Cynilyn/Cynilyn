#include <cstdio>
#include <iostream>
using namespace std;

int Answer;
int room[1000][1000];
bool visit[1000][1000];

int main(int argc, char** argv)
{
	int T, N, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		int num;
		int dx = 0, dy = 1, x = 0, y = 0;
		bool escape = false;
		scanf("%d", &N);		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &room[i][j]);
				visit[i][j] = false;
			}
		}

		while (!escape) {
			if (room[x][y] != 0) {
				visit[x][y] = 1;
				if (room[x][y] == 1) {
					dx = -dx;
					dy = -dy;
				}				
				dx ^= dy ^= dx ^= dy;
			}
			x += dx;
			y += dy;

			if (x == -1 || y == -1 || x == N || y == N) {
				escape = true;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 1) {
					Answer++;
				}
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}