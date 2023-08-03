#include<stdio.h>
#include<string.h>

int main() {
    int alpha[26];
    int n = 0;
    int i, j;
    while (n < 26) {
        alpha[n] = -1;
        n++;
    }
    char s[100];
    scanf("%s", s);
    for (i = strlen(s); i >=0; i--) {
        for (j = 0; j < 26; j++) {
            //i번째 원소가 'a', 'b', ... 'z'면
            if (s[i] == 'a' + j) {
                alpha[j] = i;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        printf("%d ", alpha[i]);
    }

    return 0;
}