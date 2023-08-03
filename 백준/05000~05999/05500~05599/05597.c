#include<stdio.h>
int main() {
	int i;
	int chk;
	int students[31] = { 0, };
	
	for (i = 0; i < 28;i++) {
		scanf("%d", &chk);
		students[chk] = 1;
	}
	for (i = 1; i <= 30; i++) {
		if (students[i] != 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}