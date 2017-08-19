#include <iostream>
using namespace std;

int main() {
	int initNum, Num;
	int count = 1;
	int pre, post;
	bool check = true;

	cin >> initNum;
	Num = initNum;

	while (check) {
		//10보다 작은 경우
		if (Num < 10) {
			pre = 0;
			post = Num;
		}
		else {
			pre = Num / 10;
			post = Num % 10;
		}		
		Num = post * 10 + (pre + post) % 10;

		//종료 조건
		if (Num == initNum) {
			check = false;
		}
		else {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}