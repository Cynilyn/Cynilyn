#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, rest, answer = 0;
	vector<int> num(10);

	cin >> N;
	while (N != 0) {
		rest = N % 10;
		N = N / 10;
		
		if (rest == 9) {
			num[6]++;
		}
		else {
			num[rest]++;
		}		
	}
	num[6] = num[6] / 2 + num[6] % 2;

	for (int i = 0; i < 10; i++) {
		answer = max(answer, num[i]);
	}

	cout << answer << endl;
	return 0;
}