#include <cstdio>
#include <math.h>
#include <algorithm>

using namespace std;

unsigned long long find_minimum(int K, unsigned long long minimum) {
	if (K == 0)
		return minimum;

	unsigned long long answer = find_minimum(K - 1, 2 * minimum);
	if ((minimum > 5) && ((minimum - 1) % 3 == 0) && (((minimum - 1) / 3) % 2 == 1))
		answer = min(answer, find_minimum(K - 1, (minimum - 1) / 3));
	return answer;
}

int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		unsigned long long maximum, minimum;
		int K;
		scanf("%d", &K);
		maximum = pow(2, K);

		minimum = find_minimum(K, 1);
		printf("Case #%d\n", test_case + 1);
		printf("%llu %llu\n", minimum, maximum);
	}
	return 0;
}