#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10002

typedef struct BigInt_ {
    char num[MAX];
    int length;
} BigInt;

BigInt fibo[MAX];

void Add(BigInt* A, BigInt* B, BigInt* result) {
    char tmpA[MAX];
    char tmpB[MAX];
    char tmp[MAX];

    int lenA = A->length;
    int lenB = B->length;

    //설정
    int delta = abs(lenA - lenB);
    int max = (abs(lenA - lenB) + lenA + lenB) / 2;

    memset(tmp, '0', sizeof(char) * (max+1));
    memset(tmpA, '0', sizeof(char) * (max+1));
    memset(tmpB, '0', sizeof(char) * (max+1));

    if (lenA > lenB) {
        memcpy(tmpA + 1, A->num, lenA);
        memcpy(tmpB + 1 + delta, B->num, lenB);
    }
    else {
        memcpy(tmpB + 1, B->num, lenB);
        memcpy(tmpA + 1 + delta, A->num, lenA);
    }
    //계산
    int iA = 0, iB = 0;
    int dA, dB;
    int C = 0, S = 0;
    for (int i = max; i > 0; i--) {
        dA = tmpA[i] - '0';
        dB = tmpB[i] - '0';
        S = dA + dB + C;
        C = S / 10;
        S %= 10;
        tmp[i] = S + '0';
    }
    if (C) {
        tmp[0] = '1';
        strcat(result->num, tmp);
    }
    else {
        strncat(result->num, tmp + 1, max);
    }
    result->length = strlen(result->num);
}

int main() {
    int N;
    strcpy(fibo[0].num, "0");
    strcpy(fibo[1].num, "1");
    fibo[0].length = fibo[1].length = 1;

    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        Add(&fibo[i - 2], &fibo[i - 1], &fibo[i]);
    }

    printf("%s\n", fibo[N].num);
    return 0;
}
