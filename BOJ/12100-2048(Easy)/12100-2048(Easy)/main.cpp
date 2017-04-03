//4방향을 사용할 때 enum형을 사용함으로써, 좀 더 직관적으로 switch문을 표현 가능
//배열을 함수의 parameter로 넘겨줄 때, 무조건 pointer형식으로 넘어감을 생각

#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_DEPTH 5

int N, MAX = 0;

enum class Direction {
	left, right, up, down
};

void memory_free(int **board)
{
	for (int i = 0; i <= N + 1; i++) 
		delete[] board[i];
	delete[] board;
}

void next_board(int depth, int **board, Direction dir) {
	if (depth > MAX_DEPTH)
		return;
	
	int **copy_board;
	copy_board = new int*[N + 2];

	for (int i = 0; i <= N + 1; i++) {
		copy_board[i] = new int[N + 1];
		memset(copy_board[i], 0, sizeof(int)*(N + 2));
	}

	switch (dir) {
	case Direction::left:
		for (int i = 1; i <= N; i++) {
			int cursor = 1;
			bool *check;
			check = new bool[N + 2];
			memset(check, false, sizeof(bool)*(N + 2));

			for (int j = 1; j <= N; j++) {
				if (board[i][j] != 0) {
					if (board[i][j] == copy_board[i][cursor - 1] && !check[cursor - 1]) {
						copy_board[i][cursor - 1] *= 2;
						check[cursor - 1] = true;
						MAX = max(MAX, copy_board[i][cursor - 1]);
					}
					else {
						copy_board[i][cursor] = board[i][j];
						MAX = max(MAX, copy_board[i][cursor]);
						cursor += 1;						
					}
				}
			}
			delete[] check;
		}

		break;

	case Direction::right:
		for (int i = 1; i <= N; i++) {
			int cursor = N;
			bool *check;
			check = new bool[N + 2];
			memset(check, false, sizeof(bool)*(N + 2));

			for (int j = N; j > 0; j--) {
				if (board[i][j] != 0) {
					if (board[i][j] == copy_board[i][cursor + 1] && !check[cursor + 1]) {
						copy_board[i][cursor + 1] *= 2;
						check[cursor + 1] = true;
						MAX = max(MAX, copy_board[i][cursor + 1]);
					}
					else {
						copy_board[i][cursor] = board[i][j];
						MAX = max(MAX, copy_board[i][cursor]);
						cursor -= 1;
					}
				}
			}
			delete[] check;
		}
		break;

	case Direction::up:
		for (int j = 1; j <= N; j++) {
			int cursor = 1;
			bool *check;
			check = new bool[N + 2];
			memset(check, false, sizeof(bool)*(N + 2));
			for (int i = 1; i <= N; i++) {
				if (board[i][j] != 0) {
					if (board[i][j] == copy_board[cursor - 1][j] && !check[cursor - 1]) {
						copy_board[cursor - 1][j] *= 2;
						check[cursor - 1] = true;
						MAX = max(MAX, copy_board[cursor - 1][j]);
					}
					else {
						copy_board[cursor][j] = board[i][j];
						MAX = max(MAX, copy_board[cursor][j]);
						cursor += 1;
					}
				}
			}
			delete[] check;
		}
		break;

	case Direction::down:
		for (int j = 1; j <= N; j++) {
			int cursor = N;
			bool *check;
			check = new bool[N + 2];
			memset(check, false, sizeof(bool)*(N + 2));
			
			for (int i = N; i > 0; i--) {
				if (board[i][j] != 0) {
					if (board[i][j] == copy_board[cursor + 1][j] && !check[cursor + 1]) {
						copy_board[cursor + 1][j] *= 2;
						check[cursor + 1] = true;
						MAX = max(MAX, copy_board[cursor + 1][j]);
					}
					else {
						copy_board[cursor][j] = board[i][j];
						MAX = max(MAX, copy_board[cursor][j]);
						cursor -= 1;
					}
				}
			}
			delete[] check;
		}
		break;
	}

	next_board(depth + 1, copy_board, Direction::left);
	next_board(depth + 1, copy_board, Direction::right);
	next_board(depth + 1, copy_board, Direction::up);
	next_board(depth + 1, copy_board, Direction::down);
	
	memory_free(copy_board);
}

int main() {
	int **board;
	scanf("%d", &N);

	board = new int*[N + 2];
	for (int i = 0; i <= N + 1; i++) {
		board[i] = new int[N + 2];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
	}

	next_board(1, board, Direction::left);
	next_board(1, board, Direction::right);
	next_board(1, board, Direction::up);
	next_board(1, board, Direction::down);
	memory_free(board);
	printf("%d\n", MAX);
	return 0;
}