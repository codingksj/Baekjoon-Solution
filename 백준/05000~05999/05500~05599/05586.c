#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* SubStr(char src[], int pos, int count) {
    int src_len = strlen(src);

    char* dest = (char*)malloc(sizeof(char) * (count + 1));

    strncpy(dest, src + pos, count);
    dest[count] = '\0'; 

    return dest;
}


int main() {
    char string[10001];
    char* result;
    int IOI = 0, JOI = 0;
    int length;

    scanf("%s", string);
    length = strlen(string);
    for (int i = 0; i < length-2; i++) {
        result = SubStr(string, i, 3);
        if (strcmp("IOI", result) == 0) {
            IOI++;
        }
        else if (strcmp("JOI", result) == 0) {
            JOI++;
        }
        free(result);
    }
    printf("%d\n%d\n", JOI, IOI);
    return 0;
}
