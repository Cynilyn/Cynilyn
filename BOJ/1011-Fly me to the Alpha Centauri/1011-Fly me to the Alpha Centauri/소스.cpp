//cmathÀÇ ceil°ú floor

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, s, e;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> s >> e;
		int distance = e - s;
		int n = 0;
		int count = 0;

		n = floor((float)sqrt(distance));
		count = 2 * n - 1 + ceil((float)(distance - n * n) / n);

		cout << count << endl;
	}

	return 0;
}