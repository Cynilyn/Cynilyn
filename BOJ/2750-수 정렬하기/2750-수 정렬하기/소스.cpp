//Insertion Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, key;
	cin >> N;
	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int j = 1; j < N; j++) {
		key = num[j];
		for (int i = j - 1; i >= 0; i--) {
			if (key < num[i]) {
				swap(num[i + 1], num[i]);
				key = num[i];
				if (i == 0) {
					break;
				}
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << num[i] << endl;
	}
	return 0;
}