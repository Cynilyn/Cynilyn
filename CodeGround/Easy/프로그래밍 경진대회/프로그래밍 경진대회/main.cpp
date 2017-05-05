#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC, N;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);
		vector<int> numList(N);
		int answer = 0, max = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &numList[i]);
		}
		sort(numList.begin(), numList.end());
		for (int i = 0; i < N; i++) {
			if (numList[i] + N - i > max)
				max = numList[i] + N - i;
		}
		for (int i = 0; i < N; i++) {
			if (numList[i] + N >= max)
				answer++;
		}
		
		printf("Case #%d\n", test_case);	
		printf("%d\n", answer);
	}

	return 0;
}