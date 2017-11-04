//2012003385_±èÁøÇö_508
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void siftUp(vector<int> &data, int cur) {
	int par = cur / 2;
	while (cur > 1 && data[par] < data[cur]) {
		swap(data[cur], data[par]);
		cur = par;
		par = cur / 2;
	}
}

void siftDown(vector<int> &data, int cur, int end) {
	int left, right, max;

	while (cur * 2 <= end) {
		left = (cur * 2);
		right = (cur * 2) + 1;

		max = cur;
		if (right <= end && data[right] > data[max]) {
			max = right;
		}
		if (data[left] > data[max]) {
			max = left;
		}

		if (max != cur) {
			swap(data[max], data[cur]);
			cur = max;
		}
		else {
			return;
		}
	}
}

int main() {
	int type, num, sub, idx, i, size = 0;
	bool finish = false;
	vector<int> data(1);

	while (!finish) {
		scanf("%d", &type);
		//insert
		if (type == 1) {
			scanf("%d", &num);
			data.push_back(num);
			size++;
			siftUp(data, size);
		}
		//extract
		else if (type == 2) {
			printf("%d ", data[1]);
			swap(data[1], data[size]);
			data.pop_back();
			size--;
			siftDown(data, 1, size);
		}
		//substitue and rearrange
		else if (type == 3) {
			scanf("%d %d", &idx, &sub);
			data[idx] = sub;
			if (idx != 1 && data[idx] > data[idx / 2]) {
				siftUp(data, idx);
			}
			else {
				siftDown(data, idx, size);
			}
		}
		//terminate
		else if (type == 0) {
			finish = true;
		}
	}

	printf("\n");
	for (i = 1; i < data.size(); i++) {
		printf("%d ", data[i]);
	}

	return 0;
}