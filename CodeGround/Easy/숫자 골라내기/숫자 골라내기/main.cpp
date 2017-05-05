#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC, N;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int tmp, answer = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			answer = answer ^ tmp;
		}

		printf("Case #%d\n", test_case);	
		printf("%d\n", answer);
	}

	return 0;
}