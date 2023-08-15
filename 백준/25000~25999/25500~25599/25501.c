#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char* s, int l, int r) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int TC;
    int pal;
    char S[1001];
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        count = 0;
        scanf("%s", &S);
        pal = isPalindrome(S);
        printf("%d %d\n", pal, count);
    }
    return 0;
}