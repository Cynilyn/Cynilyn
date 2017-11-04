#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int day, mon, quar, year;
int minCost = 987654321;
vector<int> plan(13);

void searchCost(int month, int cost) {
	if (month > 12) {
		minCost = min(minCost, cost);
		return;
	}

	searchCost(month + 1, cost + plan[month] * day);
	searchCost(month + 1, cost + mon);
	searchCost(month + 3, cost + quar);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		minCost = 987654321;

		scanf("%d %d %d %d", &day, &mon, &quar, &year);
		for (int j = 1; j <= 12; j++) {
			scanf("%d", &plan[j]);
		}

		searchCost(1, 0);

		if (year < minCost) {
			minCost = year;
		}
		
		printf("#%d %d\n", i, minCost);
	}
	return 0;
}