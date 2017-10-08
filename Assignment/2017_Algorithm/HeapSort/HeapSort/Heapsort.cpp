//2012003385_±èÁøÇö_508
#include <stdio.h>
#include <stdlib.h>

int N, K;

void swap(int *a, int *b) {
	*a ^= *b ^= *a ^= *b;
}

void siftDown(int *data, int current, int last) {
	int left;
	int right;
	int max;

	while (current * 2 <= last) {
		left = current * 2;
		right = current * 2 + 1;
		max = current;

		if (data[left] > data[max]) {
			max = left;
		}
		if (data[right] > data[max] && right <= last) {
			max = right;
		}
		if (max != current) {
			swap(&data[max], &data[current]);
			current = max;
		}
		else {
			return;
		}
	}
}

void heapify(int *data) {
	int end = N;
	int current = end >> 1;

	while (current > 0) {
		siftDown(data, current--, end);
	}
}

void heapSort(int *data) {
	heapify(data);
	int end = N;
	while (end > N - K) {
		printf("%d ", data[1]);
		swap(&data[1], &data[end--]);
		siftDown(data, 1, end);
	}
	printf("\n");
	for (int i = 1; i <= N - K; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main() {
	int i, j;
	int *data;

	scanf("%d %d", &N, &K);
	data = (int *)malloc(sizeof(int)*(N + 1));

	for (i = 1; i <= N; i++) {
		scanf("%d", &data[i]);
	}

	heapSort(data);
	free(data);
	return 0;
}