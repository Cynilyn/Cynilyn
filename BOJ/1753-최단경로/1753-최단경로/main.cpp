/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define INF 987654321
using namespace std;

int n, m, s;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;

void dijkstra(int s) {	
	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	pq.push(make_pair(s, 0));
	while (!pq.empty()) {
		int index = pq.top().first;
		int cost = -1 * pq.top().second; pq.pop();
		if (dist[index] < cost) continue;
		for (int i = 0; i < adj[index].size(); i++) {
			int n = adj[index][i].first;
			int v = adj[index][i].second;
			if (dist[n] > dist[index] + v) {
				dist[n] = dist[index] + v;
				pq.push(make_pair(n, -dist[n]));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf(dist[i] != INF ? "%d\n" : "INF\n", dist[i]);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	dijkstra(s);
}