#include <cstdio>
#include <vector>

using namespace std;

long long int Answer;

int main(int argc, char** argv)
{
	int T, test_case, N, temp;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int minimum = 987654321;
		Answer = 0;
		scanf("%d", &N);
		vector<int> height(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &height[i]);
		for (int i = 0; i < N; i++) {
			scanf("%d", &temp);
			if (temp - i < minimum)
				minimum = temp - i;
		}
			
		for (int i = 0; i < N; i++) {
			if(height[i] > minimum)
				Answer += height[i] - minimum;
		}

		printf("Case #%d\n", test_case + 1);
		printf("%lld\n", Answer);
	}

	return 0;
}