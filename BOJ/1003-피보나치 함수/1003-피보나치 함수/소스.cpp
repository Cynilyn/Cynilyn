#include <iostream>
#include <vector>
using namespace std;

int T, N;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		vector<int> arr(42, 0);
		scanf("%d", &N);
		arr[N] = 1;
		for (int n = N; n >= 2; n--) {
			arr[n - 1] += arr[n];
			arr[n - 2] += arr[n];
		}
		printf("%d %d\n", arr[0], arr[1]);
	}
	return 0;
}