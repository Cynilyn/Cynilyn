#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main(int argc, char** argv) {

	setbuf(stdout, NULL);

	int TC, N, K;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int minimum = 200, count = 0, sum = 0, tmp;
		priority_queue<int, vector<int>, greater<int> > qu;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			if (count < K) {
				qu.push(tmp);
				sum += tmp;
				count++;
			}
			else {
				minimum = qu.top();
				if (tmp > minimum) {
					sum = sum - minimum + tmp;
					qu.pop();
					qu.push(tmp);
				}
			}				
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", sum);
	}
	return 0;	
}