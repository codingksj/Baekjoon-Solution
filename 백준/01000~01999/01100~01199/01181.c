#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20001
#define MAX_L 51

char str[MAX_N][MAX_L];

int cmp(const void* a, const void* b) {
    char* str1 = (char*)a; 
    char* str2 = (char*)b;
    if (strlen(str1) == strlen(str2)) {
        return strcmp(str1, str2); // 길이가 같으면 사전순으로 정렬
    }
    else {
        return strlen(str1) - strlen(str2); // 길이 오름차순으로 정렬
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    qsort(str, n, sizeof(str[0]), cmp); 

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(str[i], str[idx]) != 0) {
            idx++;
            strcpy(str[idx], str[i]);
        }
    }
    n = idx + 1;

    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
