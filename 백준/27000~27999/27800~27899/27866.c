#include<stdio.h>
#include<string.h>
int main() {
	char word[1000];
	int n;
	scanf("%s", word);
	scanf("%d", &n);
	printf("%c", word[n-1]);
	return 0;
}