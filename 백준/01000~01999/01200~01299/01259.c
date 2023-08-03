#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<memory.h>

int main() {
	bool isFelindrome;
	int len;
	char S[6];
	while (1) {
		isFelindrome = true;
		scanf("%s", S);
		if (!strcmp(S, "0")) {
			break;
		}
		len = strlen(S);
		for (int i = 0; i <= len / 2; i++) {
			if (S[i] != S[len - 1 - i]) {
				isFelindrome = false;
				break;
			}
		}
		isFelindrome ? printf("yes\n") : printf("no\n");
	}


}