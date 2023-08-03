#include <stdio.h>

int Power(int base, int exp) {
    if(exp<0){
        return -1;
    }
    int num = 1;
    for (int i = 0; i < exp; i++) {
        num *= base;
    }
    return num;
}

void Cantor(int N) {
    int size = Power(3, N - 1);

    if (N == 0) {
        printf("-");
        return;
    }

    Cantor(N - 1);
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
    Cantor(N - 1);
}

int main() {
    int N;
    while (scanf("%d", &N)!=EOF) {
        Cantor(N);
        printf("\n");
    };
    return 0;
}
