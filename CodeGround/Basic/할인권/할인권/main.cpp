#include <cstdio>
using namespace std;
#define INF 987654321

int T, N, M, K, P;
int a, b, c, s, e;

int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_num = 1; test_num <= T; test_num++) {
		int adj[101][101];
		int answer = 0;
		//���� ��� �ʱ�ȭ
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj[i][j] = INF;
			}
		}
		//���� ��� �Է�
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a][b] = c;
			adj[b][a] = c;
		}
		//�÷��̵�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					if (adj[k][j] > adj[k][i] + adj[i][j])
						adj[k][j] = adj[k][i] + adj[i][j];
				}
			}
		}

		scanf("%d", &P);
		for (int i = 0; i < P; i++) {
			scanf("%d %d", &s, &e);
			if (K < adj[s][e])
				answer++;
		}
		printf("Case #%d\n", test_num);
		printf("%d\n", answer);
	}
	return 0;	
}