//2012003385_±èÁøÇö_508
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int N, Ans;
int tmp1, tmp2;
int entX, entY, exitX, exitY, endLine;
int line[2][101], change[2][101], L[2][101];
int S[2][2];
stack<int> path;

void dp(int num, int idx) {
	tmp1 = S[0][0] + line[num][idx];
	tmp2 = S[1][0] + line[num][idx];

	if (num == 0) {
		tmp2 += change[(num + 1)%2][idx - 1];
	}
	else {
		tmp1 += change[(num + 1)%2][idx - 1];
	}

	if (tmp1 <= tmp2) {
		S[num][1] = tmp1;
		L[num][idx] = 0;
	}
	else {
		S[num][1] = tmp2;
		L[num][idx] = 1;
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d %d", &entX, &entY);
	scanf("%d %d", &exitX, &exitY);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &line[0][i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &line[1][i]);
	}
	for (int i = 1; i < N; i++) {
		scanf("%d", &change[0][i]);
	}
	for (int i = 1; i < N; i++) {
		scanf("%d", &change[1][i]);
	}

	S[0][0] = entX + line[0][1];
	S[1][0] = entY + line[1][1];

	for (int i = 2; i <= N; i++) {
		dp(0, i);
		dp(1, i);
		S[0][0] = S[0][1];
		S[1][0] = S[1][1];
	}

	S[0][1] = S[0][0] + exitX;
	S[1][1] = S[1][0] + exitY;

	if (S[0][1] < S[1][1]) {
		printf("%d\n", S[0][1]);
		endLine = 0;
	}
	else {
		printf("%d\n", S[1][1]);
		endLine = 1;
	}

	while (N > 0) {
		path.push(endLine);
		endLine = L[endLine][N];
		N--;
	}

	int idx = 1;
	while (!path.empty()) {
		printf("%d %d\n", path.top() + 1, idx++);
		path.pop();
	}

	return 0;
}