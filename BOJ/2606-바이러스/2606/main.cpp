#include <cstdio>
#include <vector> 
#include <stack>
using namespace std;
typedef pair<int, int> gp;

int n, m, s, d;
int result = 0;

vector<gp> fw;
vector<gp>::iterator iter;
stack<int> path;
vector<int> visit(105, 0);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &d);
		if (s == 1 && visit[d - 1] != 1) {
			path.push(d);
			visit[d - 1] = 1;
		}
		else if (d == 1 && visit[s - 1] != 1) {
			path.push(s);
			visit[s - 1] = 1;
		}
		else
			fw.push_back(make_pair(s, d));
	}
	visit[0] = 1;
		
	while (!path.empty()) {
		int next = path.top();
		path.pop();
		result++;

		for (iter = fw.begin(); iter != fw.end(); ) {
			if ((*iter).first == next && visit[(*iter).second - 1] != 1) {
				path.push((*iter).second);
				visit[(*iter).second - 1] = 1;
				iter = fw.erase(iter);
			}
			else if ((*iter).second == next && visit[(*iter).first - 1] != 1) {
				path.push((*iter).first);
				visit[(*iter).first - 1] = 1;
				iter = fw.erase(iter);
			}
			else
				++iter;
		}
	}
	printf("%d\n", result);
	return 0;
}