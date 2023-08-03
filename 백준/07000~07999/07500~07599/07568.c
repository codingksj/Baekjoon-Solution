#include<stdio.h>
#include<string.h>

int main() {
	int H[51] = {};
	int W[51] = {};
	int i, j;
	int N;
	int index = 0;
	int size;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &W[i], &H[i]);
	}
	
	for (i = 0; i < N; i++) {
		size = 1;
		for (j = 0; j < N; j++) {
			if (j == index)
				continue;
			if (W[index] < W[j] && H[index] < H[j])
				size++;
			else
				continue;
		}
		printf("%d ", size);
		index++;
	
	}
		
	return 0;
}