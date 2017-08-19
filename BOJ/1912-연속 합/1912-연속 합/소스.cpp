#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, maxValue;

	cin >> N;

	vector<int> num(N + 1);
	vector<int> sum(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	sum[N] = num[N];
	maxValue = sum[N];


	//dp�� Ǯ�� ��.
	//���������� �ִ� �����հ� ���� �迭 ���� ���� ���� ��
	for (int i = N - 1; i >= 1; i--) {
		sum[i] = max(sum[i + 1] + num[i], num[i]);
		maxValue = max(maxValue, sum[i]);
	}

	cout << maxValue << endl;
	return 0;
}