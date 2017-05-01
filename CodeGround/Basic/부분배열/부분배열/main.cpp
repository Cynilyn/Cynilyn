#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, S;
int num[100010];

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		queue<int> qu;
		int sum = 0, answer = 0;
		scanf("%d %d", &N, &S);

		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
			qu.push(num[i]);
			sum += num[i];
			while (sum >= S) {
				if (!answer || answer > qu.size())
					answer = qu.size();
				sum -= qu.front();
				qu.pop();
			}				
		}		
		printf("#testcase%d\n", test_case);
		printf("%d\n", answer);
	}

	return 0;
}