//2012003385_±èÁøÇö_508
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, u, v, w, num, answer;
vector<vector<pair<int, int> > > edge;

vector<int> Dijkstra(int s) {
	vector<int> dist(N + 1, -1);
	priority_queue<pair<int, int> > pq;
	dist[s] = 0;
	pq.push(make_pair(-dist[s], s));
	while (!pq.empty()) {
		int here = pq.top().second;
		int heredist = -pq.top().first;
		pq.pop();
		if (heredist > dist[here]) continue;
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i].first;
			int nextdist = heredist + edge[here][i].second;
			if (dist[there] == -1 || dist[there] > nextdist) {
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}

	return dist;
}

int main() {
	scanf("%d", &N);
	edge.resize(N + 1);

	while (scanf("%d %d", &u, &num) != EOF) {
		for (int i = 0; i < num; i++) {
			scanf("%d %d", &v, &w);
			edge[u].push_back(make_pair(v, w));
		}
	}

	vector<int> dist = Dijkstra(1);

	answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dist[i]);
	}
	printf("%d\n", answer);

	return 0;
}