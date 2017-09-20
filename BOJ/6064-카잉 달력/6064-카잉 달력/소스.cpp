#include <iostream>
#include <algorithm>
using namespace std;

int getlcm(int a, int b) {
	int x = a, y = b;

	while (1) {
		int n = x % y;
		if (n == 0) break;
		x = y;
		y = n;
	}
	return (a * b) / y;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, x, y, now;
		int gcm, lcm;
		int answer = -1;
		cin >> M >> N >> x >> y;

		lcm = getlcm(M, N);

		if (M < N) {
			swap(M, N);
			swap(x, y);
		}

		now = x;
		while (now <= lcm) {
			if (!((now - y) % N)) {
				answer = now;
				break;
			}
			now += M;
		}
		cout << answer << endl;
	}
	return 0;
}