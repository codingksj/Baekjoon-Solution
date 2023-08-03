#include<stdio.h>
#include<string.h>

int main() {
    int test;
    int len, i, j;
    int repeat = 0;
    char c;
    char s[20];
    scanf("%d", &test);
    while (test>0) {
        scanf("%d %s", &repeat, s);
        len = strlen(s);
        for (i = 0; i < len; i++) {
            for (j = 0; j < repeat; j++) {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        test--;
    }
    return 0;
}