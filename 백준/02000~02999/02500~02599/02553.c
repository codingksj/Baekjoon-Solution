#include <stdio.h>
#include <math.h>

int main() {
    long long N;
    long long fact = 1;
    int last_digit = 1;
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++) {
        fact *= i;
        fact %= 100000000;
        //0이 있으면 없앤다
        while (fact % 10 == 0)
            fact /= 10;
    }
    last_digit = fact % 10;
   
    printf("%d", last_digit);
}