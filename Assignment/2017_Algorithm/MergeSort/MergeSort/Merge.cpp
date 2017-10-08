//2012003385_±èÁøÇö_508
#include <stdio.h>
#include <stdlib.h>

int N;

void Merge(int *data, int left, int mid, int right) {
	int i, j, k, m;
	int *temp;
	i = left;
	j = mid + 1;
	k = left;

	temp = (int *)malloc(sizeof(int) * N);

	while (i <= mid && j <= right) {
		temp[k++] = (data[i] > data[j]) ? data[i++] : data[j++];
	}

	while (i <= mid) {
		temp[k++] = data[i++];
	}
	while (j <= right) {
		temp[k++] = data[j++];
	}

	for (i = left; i <= right; i++) {
		data[i] = temp[i];
	}	
	free(temp);
}

void MergeSort(int *data, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(data, left, mid);
		MergeSort(data, mid + 1, right);
		Merge(data, left, mid, right);
	}
}

int main() {
	int i;
	int *data;
	scanf("%d", &N);
	data = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}

	MergeSort(data, 0, N - 1);

	for (i = 0; i < N; i++) {
		printf("%d\n", data[i]);
	}
	free(data);
	return 0;
}