#include <cstdio>
using namespace std;

int main() {
	int a, b, v, tmp, answer;
	scanf("%d %d %d", &a, &b, &v);
	tmp = (v - a) % (a - b);
	if (tmp == 0)
		answer = (v - a) / (a - b) + 1;
	else
		answer = (v - a) / (a - b) + 2;
	printf("%d\n", answer);
	return 0;
}