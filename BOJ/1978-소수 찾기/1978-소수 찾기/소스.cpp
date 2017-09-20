#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, count = 0;
	cin >> N;
	vector<bool> sosu(1001, true);
	
	sosu[1] = false;
	for (int i = 2; i <= 32; i++) {
		if (sosu[i] == false) {
			continue;
		}
		for(int j = i + i; j <= 1000; j += i){
			sosu[j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (sosu[num]) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}