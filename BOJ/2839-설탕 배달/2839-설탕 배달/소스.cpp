#include <iostream>
using namespace std;

int main() {
	int N, five, three;
	int count = 3;

	cin >> N;

	//5개 짜리봉지를 최대한 들고 갔을 경우
	five = N / 5;
	N = N % 5;

	//최대 공약수가 15이므로 5개 봉지로 3번까지 뺄 수 있음
	//그래서 count 초기값은 3이고 0이 되는 순간 모든 기회가 소진된 것이므로 탈출
	//또한 낮은 숫자에 대해 five가 음수가 되는 경우도 발생, 이 경우도 탈출
	while (count > 0 && five >= 0) {

		//3개짜리 봉지로 가져갈 수 있으면
		if (N % 3 == 0) {
			three = N / 3;
			break;
		}
		else {
			N += 5;
			count--;
			five--;
		}
	}

	if (count == 0 || five < 0) {
		cout << -1 << endl;
	}
	else {
		cout << five + three << endl;
	}

	return 0;
}