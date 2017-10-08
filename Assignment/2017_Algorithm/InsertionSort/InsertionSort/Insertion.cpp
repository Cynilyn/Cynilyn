//2012003385_±èÁøÇö_508
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, j, key;
	int *insertion;

	scanf("%d", &N);
	insertion = (int *)malloc(sizeof(int) * N);
	scanf("%d", &insertion[0]);

	for (i = 1; i < N; i++) {
		scanf("%\d", &insertion[i]);
		key = insertion[(j = i)];
		while (--j >= 0 && insertion[j] < key) {
			insertion[j + 1] = insertion[j];
		}
		insertion[j + 1] = key;
	}

	for (i = 0; i < N; i++) {
		printf("%d\n", insertion[i]);
	}
	free(insertion);

	return 0;
}