#include <iostream>
using namespace std;

int main() {
	int N, five, three;
	int count = 3;

	cin >> N;

	//5�� ¥�������� �ִ��� ��� ���� ���
	five = N / 5;
	N = N % 5;

	//�ִ� ������� 15�̹Ƿ� 5�� ������ 3������ �� �� ����
	//�׷��� count �ʱⰪ�� 3�̰� 0�� �Ǵ� ���� ��� ��ȸ�� ������ ���̹Ƿ� Ż��
	//���� ���� ���ڿ� ���� five�� ������ �Ǵ� ��쵵 �߻�, �� ��쵵 Ż��
	while (count > 0 && five >= 0) {

		//3��¥�� ������ ������ �� ������
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