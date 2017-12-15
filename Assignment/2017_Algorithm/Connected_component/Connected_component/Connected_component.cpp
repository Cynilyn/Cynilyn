//2012003385_±èÁøÇö_508
#include <cstdio>
#include <vector>
using namespace std;

int N, u, v, root, idx = 0;

struct DisjointSet {
	vector<int> parent, rank, cc;
	DisjointSet(int n) : parent(n + 1), rank(n + 1, 1), cc(n + 1, -1) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) {
			return;
		}

		idx++;
		if (rank[u] > rank[v]) {
			swap(u, v);
		}
		parent[u] = v;

		if (rank[u] == rank[v]) {
			++rank[v];
		}
	}
};

int main() {
	scanf("%d", &N);

	DisjointSet dis(N);

	while (scanf("%d %d", &u, &v) != EOF) {
		dis.merge(u, v);
	}

	printf("%d\n", N - idx);
	idx = 1;
	for (int i = 1; i <= N; i++) {
		root = dis.find(i);
		if (dis.cc[root] == -1) {
			dis.cc[root] = idx;
			idx++;
		}
		printf("%d\n", dis.cc[root]);
	}

	return 0;
}