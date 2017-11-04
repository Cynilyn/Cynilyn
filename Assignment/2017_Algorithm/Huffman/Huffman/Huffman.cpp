//2012003385_±èÁøÇö_508
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct huff{
	char str[4];
	int freq;
	int left;
	int right;
};

bool operator < (huff a, huff b) {
	return a.freq > b.freq;
}

int N, S, Answer = 0;
priority_queue<huff> HuffMan;
vector<huff> result;

void search_tree(int idx, int level) {
	if (strcmp(result[idx].str, "") != 0) {
		Answer += level * result[idx].freq;
	}

	if (result[idx].left != 0) {
		search_tree(result[idx].left, level + 1);
	}
	if (result[idx].right != 0) {
		search_tree(result[idx].right, level + 1);
	}
}

int main() {
	scanf("%d", &N);
	result.resize(2 * N - 1);
	for (int i = 0; i < N; i++) {
		huff temp = { "", 0, 0, 0 };
		scanf("%4s", temp.str);
		scanf("%d", &temp.freq);
		HuffMan.push(temp);
	}
	scanf("%d", &S);

	int idx = 2 * N - 2;
	while (idx > 0) {
		huff temp = {};

		result[idx] = HuffMan.top();
		temp.left = idx;
		temp.freq = result[idx--].freq;
		HuffMan.pop();

		result[idx] = HuffMan.top();
		temp.right = idx;
		temp.freq += result[idx--].freq;
		HuffMan.pop();

		HuffMan.push(temp);
	}
	result[0] = HuffMan.top();
	HuffMan.pop();

	search_tree(0, 0);

	int count = 0;
	while (N > 0) {
		N = N / 2;
		count++;
	}

	printf("%d\n", S * count);
	printf("%d\n", Answer);

	return 0;
}