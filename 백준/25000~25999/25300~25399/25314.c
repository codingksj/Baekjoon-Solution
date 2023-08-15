#include<stdio.h>

int main() {
    int n, i=0;
    scanf("%d", &n);

    while (i < (n/4)) {
        printf("long ");
        i++;
    }
    printf("int");
    return 0;
}