#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, answer;
	cin >> N;
	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	
	answer = num[0] * num[N - 1];
	cout << answer << endl;
	return 0;
}