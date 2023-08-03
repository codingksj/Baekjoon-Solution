#include<stdio.h>
#include<string.h>
int main() {
	int N;
	int i = 0;
	
	scanf("%d", &N);
	
	while (N>0) {
		++i;
		N -= i;
		
	}
	if (i % 2 == 0)
		printf("%d/%d", i + N, 1 - N);
	else
		printf("%d/%d", 1 - N, i + N);
	return 0;
}