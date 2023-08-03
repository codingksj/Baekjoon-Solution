#include <stdio.h>

typedef long long LL;
int main(){
    LL a,b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", (a-b) > 0 ? a-b : b-a);
    return 0;
}