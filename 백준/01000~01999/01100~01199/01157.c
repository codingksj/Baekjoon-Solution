#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cctype>

#define SIZE 26

int main() {
    int len, i;
    int alpha[SIZE] = { 0, };
    int max=0, max_count=0;
    int max_index;

    char s[1000000];
    char c;
    scanf("%s", &s, sizeof(s));
    
    len = strlen(s);
    for (i = 0; i < len;i++) {
        c = toupper(s[i]);
        alpha[c - 'A']++;
    }
    
    for (i = 0; i < SIZE; i++) {
        if (max<alpha[i]) {
            max = alpha[i];
            max_index = i;
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (max == alpha[i]) {
            max_count++;
        }
    }

    max_count > 1 ? printf("?") : printf("%c", 'A' + max_index);
    
    return 0;
}