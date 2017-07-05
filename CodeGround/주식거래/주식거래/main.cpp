#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, dayTotal;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> dayTotal;
		vector<int> stock(dayTotal);
		vector<bool> dp(dayTotal);
		for (int i = 0; i < dayTotal; i++) {
			cin >> stock[i];
		}
		
		if (dayTotal >= 3) {
			for (int i = 1; i < dayTotal - 1; i++) {
				if (stock[i + 1] < stock[i] && stock[i - 1] < stock[i]) {
					Answer++;
				}
			}
			if (stock[dayTotal - 1] > stock[dayTotal - 2])
				Answer++;
		}

		else if (dayTotal == 1) {
			Answer = 0;
		}

		else if (dayTotal == 2) {
			if (stock[1] > stock[0])
				Answer++;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer*2 << endl;
	}

	return 0;
}