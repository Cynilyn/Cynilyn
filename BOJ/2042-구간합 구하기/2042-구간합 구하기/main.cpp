#include <cstdio>
#include <vector>
using namespace std;
long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<long long> &tree, int i, long long num) {
	while (i < tree.size()) {
		tree[i] += num;
		i += (i & -i);
	}
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<long long> A(N + 1);
	vector<long long> tree(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		update(tree, i, A[i]);
	}

	for (int i = 1; i <= M + K; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp - 1) {
			int s, e;
			scanf("%d %d", &s, &e);
			printf("%lld\n", sum(tree, e) - sum(tree, s-1));
		}
		else {
			int index;
			long long num;
			scanf("%d %lld", &index, &num);
			long long temp = num - A[index];
			A[index] = num;
			update(tree, index, temp);
		}
	}
	return 0;
}