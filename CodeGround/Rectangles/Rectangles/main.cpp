#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
	long long x1, y1, x2, y2;
};

int Answer, N, M, K;
vector<Rectangle> rec(5001);
vector<int> Sum(5001);

bool isInclude(Rectangle r1, Rectangle r2) {
	if (r1.x1 <= r2.x1 && r2.x2 <= r1.x2 && r1.y1 <= r2.y1 && r2.y2 <= r1.y2)
		return true;
	return false;
}

int FindSum(int index) {
	int ans = 1;
	if (Sum[index] > 0)
		return Sum[index];
	for (int i = 1; i <= K; i++) {
		if ((index != i) && isInclude(rec[index], rec[i])) {
			ans = max(ans, FindSum(i) + 1);
		}
	}
	return Sum[index] = ans;
}

int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		scanf("%d %d %d", &N, &M, &K);
		Rectangle empty;
		rec.assign(K + 1, empty);
		Sum.assign(K + 1, 0);
		for (int i = 1; i <= K; i++)
			scanf("%lld %lld %lld %lld", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);

		for (int i = 1; i <= K; i++) {
			Answer = max(Answer, FindSum(i));
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;
}