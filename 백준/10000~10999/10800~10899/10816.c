#include <stdio.h>

#define MAX 20000002
#define T 10000000
int cards[MAX];

int main()
{
    int M, N;
    int tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        cards[tmp+T]++;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&tmp);
        printf("%d ",cards[tmp+T]);
    }
    return 0;
}
