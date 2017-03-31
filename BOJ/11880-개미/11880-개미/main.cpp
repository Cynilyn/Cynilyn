#include <cstdio>
#define min(a,b) a < b? a : b
using namespace std;

int main() {
	int T;
	long long int a, b, c;
	long long int answer;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		answer = min((a + c)*(a + c) + b*b, (b + c)*(b + c) + a*a);
		answer = min(answer, (a + b)*(a + b) + c*c);
		printf("%lld\n", answer);
	}
}