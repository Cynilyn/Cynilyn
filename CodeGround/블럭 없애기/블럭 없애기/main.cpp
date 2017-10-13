#include <iostream>
#include <cstdio>

using namespace std;

int Answer;
int block[100002];

int main(int argc, char** argv)
{
	int T, N, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j;
		Answer = 0;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &block[i]);
		}
		block[0] = 0;
		block[N + 1] = 0;
		
		for (i = 1; i <= N; i++) {
			if (block[i] > block[i - 1] + 1) {
				block[i] = block[i - 1] + 1;
			}
		}

		for (i = N; i >= 1; i--) {
			if (block[i] > block[i + 1] + 1) {
				block[i] = block[i + 1] + 1;
			}
			if (block[i] > Answer) {
				Answer = block[i];
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}