#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int main() {
    bool end, mul, fac;
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        end = (a == 0) && (b == 0);
        mul = a % b == 0;
        fac = b % a == 0;
        if (end) {
            break;
        }
        else if (mul) {
            printf("multiple\n");
        }
        else if (fac) {
            printf("factor\n");
        }
        else {
            printf("neither\n");
        }
    }

    return 0;
}
