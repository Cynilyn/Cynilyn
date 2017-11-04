#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int T, N, M, C;
int ans;
int honey[10][10];
int price[10][10];
int total[10][10];

void calcMax(int x, int y, int range) {
	int count, sum;
	int temp, maxValue = 0;
	total[x][y] = 0;

	for (int i = range - 1; i >= 0; i--) {
 		count = M - 1, sum = 0, temp = 0;
		while (count >= 0) {
			if (i >> count & 1) {
				sum += honey[x][y + count];
				temp += price[x][y + count];
			}
			count--;
		}
		if (sum <= C) {
			maxValue = max(maxValue, temp);
			total[x][y] = maxValue;
		}
	}
}

int calcAns(int x, int y) {
	int first = total[x][y];
	int second = 0, sum;
	for (int i = 0; i + M <= y; i++) {
		second = max(second, total[x][i]);
	}
	for (int i = y + M; i < N - M + 1; i++) {
		second = max(second, total[x][i]);
	}
	sum = first + second;
	second = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (i != x) {
				second = max(second, total[i][j]);
			}			
		}
	}
	sum = max(sum, first + second);

	return sum;
}

void sol() {
	int range = pow(2, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			calcMax(i, j, range);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			ans = max(ans, calcAns(i, j));
		}
	}
}


int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		ans = 0;
		scanf("%d %d %d", &N, &M, &C);

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &honey[j][k]);
				price[j][k] = honey[j][k] * honey[j][k];
			}
		}

		sol();

		printf("#%d %d\n", i, ans);
	}
	return 0;
}