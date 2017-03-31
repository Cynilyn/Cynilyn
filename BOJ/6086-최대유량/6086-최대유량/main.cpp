#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 987654321

inline int CtoI(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	int N;
	int c[52][52] = { 0 };
	int f[52][52] = { 0 };
	vector<int> adj[52];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char u, v;
		int cost;
		scanf(" %c %c %d", &u, &v, &cost);
		u = CtoI(u);	v = CtoI(v);
		c[u][v] += cost;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int total = 0, S = CtoI('A'), E = CtoI('Z');
	while (1) {
		int prev[52];
		fill(prev, prev + 52, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					if (next == E) break;
				}
			}
		}

		if (prev[E] == -1) break;
		int flow = MAX;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}