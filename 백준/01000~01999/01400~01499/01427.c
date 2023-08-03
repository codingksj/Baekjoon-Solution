#include<stdio.h>
#include<string.h>

void Swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // 정렬에 쓸 변수
    char S[11];
    int i, j, len;

    scanf("%s", S);
    len = strlen(S);
    for (i = 0; i < len - 1; i++) {
        j = i;
        while (j >= 0 && (S[j] < S[j + 1])) {
            Swap(&S[j], &S[j + 1]);
            j--;
        }
    }
    printf("%s\n", S);
    return 0;
}
