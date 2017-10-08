//2012003385_±èÁøÇö_508
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, i, j, min, index;
	int *data;
	scanf("%d %d", &N, &M);

	data = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}

	for (i = 0; i < M; i++) {
		min = data[i];
		index = i;
		for (j = i + 1; j < N; j++) {
			if (min > data[j]) {
				min = data[j];
				index = j;
			}
		}
		data[i] ^= data[index] ^= data[i] ^= data[index];
	}

	for (i = 0; i < N; i++) {
		printf("%d\n", data[i]);
	}

	free(data);
	return 0;
}