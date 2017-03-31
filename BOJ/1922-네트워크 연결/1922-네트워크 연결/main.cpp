/*
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> cycle(1001);

typedef struct adj {
	int start, end, cost;
};

bool operator < (adj t, adj u) {
	return t.cost > u.cost;
}

int find_parent(int index) {
	if (cycle[index] != index)
		return find_parent(cycle[index]);
	return index;
}

int main() {
	int N, M, ans = 0, edg_cnt = 0;
	priority_queue<adj> pq;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++) {
		adj temp;
		scanf("%d %d %d", &temp.start, &temp.end, &temp.cost);
		pq.push(temp);
	}

	for (int i = 0; i <= 1000; i++)
		cycle[i] = i;

	while (edg_cnt < N-1) {
		adj temp = pq.top();	pq.pop();
		if (find_parent(temp.start) != find_parent(temp.end)) {
			cycle[find_parent(temp.end)] = temp.start;
			ans += temp.cost;
			edg_cnt++;
		}
	}
	printf("%d\n", ans);
}