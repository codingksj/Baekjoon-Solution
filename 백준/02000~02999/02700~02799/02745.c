#include<stdio.h>
#include<string.h>
int main() {
	char s[30];
	int N;
	int i;
	int decimal = 0;
	int W = 1;

	scanf("%s", s);
	scanf("%d", &N);
	for (i = strlen(s) - 1; i >= 0; i--) {
		//가중치 * 자리수만큼 곱한다
		if (s[i] >= '0' && s[i] <= '9') {
			decimal += (s[i] - '0') * W;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			decimal += (s[i] - 'A' + 10) * W;
		}
		W *= N;
	}
	
	printf("%d", decimal);
	return 0;
}