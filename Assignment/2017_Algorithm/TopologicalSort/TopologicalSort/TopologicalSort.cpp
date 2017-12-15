//2012003385_±èÁøÇö_508
#include <cstdio>
using namespace std;
#define MAX 1000

typedef struct Node {
	int predec, s_time, f_time;
	char color;
	Node() : predec(0), s_time(0), f_time(0), color('W') {

	}
}Node;

int N, u, v, time = 0;
int edge[MAX][MAX];
int answer[MAX];
Node node[MAX];

void dfs(int here) {
	time++;
	node[here].s_time = time;
	node[here].color = 'G';

	for (int there = 1; there <= N; there++) {
		if (edge[here][there] == 1) {
			if (node[there].color == 'W') {
				node[there].predec = here;
				dfs(there);
			}
		}
	}

	node[here].color = 'B';
	time++;
	node[here].f_time = time;
}

int check_cycle() {
	for (int here = 1; here < N; here++) {
		for (int there = 1; there < N; there++) {
			if (edge[here][there] == 1) {
				if (node[here].f_time < node[there].f_time) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d", &N);

	while (scanf("%d %d", &u, &v) != EOF) {
		edge[u][v] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (node[i].color == 'W') {
			dfs(i);
		}
	}

	int dag = check_cycle();

	printf("%d\n", dag);
	if (dag == 1) {
		for (int i = 1; i <= N; i++)
			answer[node[i].f_time] = i;

		for (int i = time; i > 0; i--)
		{
			if (answer[i] != 0)
				printf("%d ", answer[i]);
		}
	}

	return 0;
}