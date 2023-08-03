#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<memory.h>

int main() {
	int i,j;
	int TC;
	int iS,iE;
	int len;
	int count = 0;
	int start_pos[26], end_pos[26];
	bool flag;
	char alpha[100];

	scanf("%d", &TC);
	while (TC--) {
		memset(start_pos, -1, sizeof(int)*26);
		memset(end_pos, -1, sizeof(int)*26);
		flag = true;

		scanf("%s", alpha);
		len = strlen(alpha);

		for (i = 0; i < len; i++) {
			iE = alpha[i] - 'a';
			end_pos[iE] = i;
		}
		for (i = len-1; i>=0; i--) {
			iS = alpha[i] - 'a';
			start_pos[iS] = i;
		}

		for (i = 0; i < 26; i++) {
			if (start_pos[i] == -1) {
				continue;
			}
			for (j = start_pos[i]; j < end_pos[i]; j++) {
				if (alpha[j] != 'a' + i) {
					flag = false;
					i = 26;
					break;
				}
			}
		}
		flag &&	count++;
	}
	printf("%d\n", count);
	return 0;
}