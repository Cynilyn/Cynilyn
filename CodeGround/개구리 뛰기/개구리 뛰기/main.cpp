#include <iostream>
#include <cstdio>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, N, K, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		scanf("%d", &N);

		int *stone = new int[N];
		for (int j = 0; j < N; j++) {
			scanf("%d", &stone[j]);
		}
		scanf("%d", &K);

		int now = 0;
		int tmp = 0;

		for (int j = 0; j < N; j++) {
			tmp = now + K;
			if (tmp >= stone[j]) {
				if (j == N - 1) {
					Answer++;
					break;
				}
				if (tmp < stone[j + 1]) {
					Answer++;
					now = stone[j];
				}
			}
			else {
				Answer = -1;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}