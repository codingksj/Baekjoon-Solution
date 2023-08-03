#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    int A, B;
    int OA, OB;
    int a, b, tmp;
    int i;
    int LCM;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        OA = A, OB = B;
        if (A > B) {
            tmp = A;
            A = B;
            B = tmp;
        }
        while (A%B != 0) {
            a = B;
            b = A % B;
            A = a;
            B = b;
        }
        LCM = OA * OB / B;
        printf("%d\n", LCM);
    }

   
    return 0;
}
