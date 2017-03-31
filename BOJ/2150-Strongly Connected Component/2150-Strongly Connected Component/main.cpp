#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E, A, B, scc_size = 0;
stack<int> st;

void DFS(int index, vector<vector<int> >& adj, vector<bool>& det) {
	det[index] = 1;
	for (int i = 0; i < adj[index].size(); i++) {
		if (!det[adj[index][i]])
			DFS(adj[index][i], adj, det);
	}
	st.push(index);
}

void reverse_DFS(int index, vector<vector<int> >& reverse_adj, vector<bool>& det,
	vector<vector<int> >& scc) {
	det[index] = 0;
	scc[scc_size].push_back(index);
	for (int i = 0; i < reverse_adj[index].size(); i++) {
		if (det[reverse_adj[index][i]])
			reverse_DFS(reverse_adj[index][i], reverse_adj, det, scc);
	}	
}

int main() {
	scanf("%d %d", &V, &E);
	vector<vector<int> > adj(V + 1);
	vector<vector<int> > reverse_adj(V + 1);
	vector<vector<int> > scc(V + 1);
	vector<bool> det(V + 1, false);

	for (int i = 0; i < E; i++) {
		scanf("%d %d", &A, &B);
		adj[A].push_back(B);
		reverse_adj[B].push_back(A);
	}

	for (int i = 1; i <= V; i++) {
		if (!det[i])
			DFS(i, adj, det);
	}

	while (!st.empty()) {
		if (det[st.top()]) {
			reverse_DFS(st.top(), reverse_adj, det, scc);
			scc_size++;
		}			
		st.pop();		
	}

	scc.resize(scc_size);
	for (int i = 0; i < scc_size; i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());

	printf("%d\n", scc_size);
	for (int i = 0; i < scc_size; i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}