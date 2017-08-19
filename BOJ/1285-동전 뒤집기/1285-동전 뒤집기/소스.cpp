#include <cstdio>
#include <cmath>

int N;
bool originalCoin[21][21];
bool cpyCoin[21][21];
bool binary[21];

void makeBinaryArray(int num) {
	for (int i = 0; i < N; i++) {
		binary[i] = num % 2;
		num = num / 2;
	}
}

void reverseCoin(int i) {
	for (int j = 0; j < N; j++) {
		cpyCoin[i][j] = !originalCoin[i][j];
	}
}

void copyCoin(int i) {
	for (int j = 0; j < N; j++) {
		cpyCoin[i][j] = originalCoin[i][j];
	}
}

int main() {
	int repeat, HSUM, TSUM, AnswerTemp;
	int Answer = 987654321;
	char c;

	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &c);
			c == 'H' ? originalCoin[i][j] = 1 : originalCoin[i][j] = 0;
		}
		scanf("%c", &c);
	}

	repeat = pow(2, N);
	
	for (int idx = 0; idx < repeat; idx++) {
		makeBinaryArray(idx);
		for (int i = 0; i < N; i++) {
			if (binary[i] == 1) {
				reverseCoin(i);
			}
			else {
				copyCoin(i);
			}
		}

		AnswerTemp = 0;
		for (int j = 0; j < N; j++) {
			HSUM = 0, TSUM = 0;
			for (int i = 0; i < N; i++) {
				cpyCoin[i][j] == 1 ? HSUM++ : TSUM++;
			}
			HSUM < TSUM ? AnswerTemp += HSUM : AnswerTemp += TSUM;
		}
		
		if (AnswerTemp < Answer) {
			Answer = AnswerTemp;
		}			
	}

	printf("%d\n", Answer);
}